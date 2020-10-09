#include "stdafx.h"
#include "WindowBase.h"

/**
 * @brief main関数からインスタンスハンドルを受け取ってウインドウ作ったりする
 */
class ApplicationBase
{
private:
protected:
    /**
     * @brief   ウインドウクラスを登録する関数
     * @return  成功:S_OK   失敗:S_FALSE
     */
    virtual HRESULT RegistWndClass();

    /**
     * @brief   ウインドウ作成関数
     * @return  成功:S_OK   失敗:S_FALSE
     */
    virtual HRESULT CreateMainWindow();

    /**
     * @brief   諸々の初期化
     * @return  成功:S_OK   失敗:S_FALSE
     */
    virtual HRESULT Initialize();

    /**
     * @brief   メインループ
     * @return  成功:S_OK   失敗:S_FALSE
     */
    virtual HRESULT Update();

    /**
     * @brief   解放
     * @return  成功:S_OK   失敗:S_FALSE
     */
    virtual HRESULT Release();

protected:
    HINSTANCE                       m_hInst;        //インスタンスハンドル  DXのほか、サウンドなどいろいろ使用する
    WNDCLASSEX                      m_WndClass;     //ウインドウクラス
    std::vector<std::unique_ptr<WindowBase>> m_pWindowAry;   //ウインドウ配列
public:
    /**
     * @brief   コンストラクタ
     */
    ApplicationBase();

    /**
     * @brief   インスタンスハンドルを取得
     */
    HINSTANCE GetInstance();

    /**
     * @brief   使用しているウインドウをコールバック関数で使用するための関数
     */
    std::vector<std::unique_ptr<WindowBase>>* GetWndPtr();

    /**
     * @brief   ウインドウプロシージャ
     * @param   hWnd    HWND    ウインドウハンドル
     * @param   UINT    msg     メッセージ番号
     * @param   WPARAM  wParam  msgの追加情報
     * @param   LPARAM  lParam  msgの追加情報
     */
    virtual LRESULT CALLBACK GrobalWndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

    /**
     * @brief   実行
     */
    HRESULT Run(HINSTANCE hInst);
};

//ウインドウプロシージャでウインドウごとにメッセージを処理するのでグローバルに置く必要がある
ApplicationBase* pApp;