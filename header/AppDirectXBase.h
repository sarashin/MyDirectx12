#include "ApplicationBase.h"

class AppDirectXBase : public ApplicationBase
{
private:
protected:
    /**
     * @brief   ウインドウクラスを登録する関数
     * @return  成功:S_OK   失敗:S_FALSE
     */
    HRESULT RegistWndClass();

    /**
     * @brief   ウインドウ作成関数
     * @return  成功:S_OK   失敗:S_FALSE
     */
    HRESULT CreateMainWindow();

    /**
     * @brief   諸々の初期化
     * @return  成功:S_OK   失敗:S_FALSE
     */
    HRESULT Initialize();

    /**
     * @brief   メインループ
     * @return  成功:S_OK   失敗:S_FALSE
     */
    HRESULT Update();

    /**
     * @brief   解放
     * @return  成功:S_OK   失敗:S_FALSE
     */
    HRESULT Release();

protected:
    
public:
    AppDirectXBase();
    ~AppDirectXBase();
    HRESULT Run(HINSTANCE hInst);
};