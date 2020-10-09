/**
 * @brief   COM用スマートポインタクラス
 */
namespace MyLib{
    template <class T> class ComPtr
    {
    private:
        T* m_pInterface;
    protected:
        /**
         * @brief   参照カウンタ増加
         */
        void AddRef(T* pInterface){
            pInterface->AddRef();
        }

        /**
         * @brief   参照カウンタ減少
         */
        void Release(){
            m_pInterface->Release();
        }
    public:
        /**
         * @brief   コンストラクタ
         * @param   T       pInterface  COMオブジェクト
         * @param   bool    isRelease   削除権限を譲渡するかどうか
         */
        explicit ComPtr(T* pInterface, bool isRelease){
            if(pInterface && isRelease){
                pInterface->Release();

                m_pInterface=pInterface;
            }
        }

        /**
         * @brief   コピーコンストラクタ
         * @param   T       pInterface  COMオブジェクト
         */
        ComPtr(const ComPtr& src){
                if(src.m_pInterface){
                    src.m_pInterface->AddRef();
                }

                m_pInterface=src.m_pInterface;
        }

        /**
         * @brief   デストラクタ
         */
        virtual ~ComPtr(){
            if(m_pInterface){
                m_pInterface->Release();
            }
        }

        /**
         * @brief   =のオーバーロード(コピー)   
         */
        ComPtr& operator=(const ComPtr& src){
            if(src.m_pInterface){
                src.m_pInterface->AddRef();
            }

            //既に何らかのポインタを保持しているか
            if(m_pInterface){
                m_pInterface->Release();
            }

            m_pInterface=src.m_pInterface;

            return *this;
        }

        /**
         * @brief   =のオーバーロード(登録)
         */
        void operator=(const T* pInterface){
            if(m_pInterface){
                Release(m_pInterface);
            }

            m_pInterface=pInterface;
        }

        /**
         * @brief   ==のオーバーロード
         */
        bool operator ==(int val){
            return val==(int)m_pInterface;
        }

        /**
         * @brief   !=のオーバーロード
         */
        bool operator !=(int val){
            return val!=(int)m_pInterface;
        }

        /**
         * @brief   ポインタ取得
         */
        T* GetPtr(){
            return m_pInterface;
        }

        /**
         * @brief   ポインタのアドレス取得
         */
        T** GetAddressOf(){
            return &m_pInterface;
        }

        /**
         * @brief   生成関数に渡す時に参照を減らす。
         */
        T** ToCreator(){
            if(m_pInterface){
                m_pInterface->Release();
            }

            return &m_pInterface;
        }
    };
}