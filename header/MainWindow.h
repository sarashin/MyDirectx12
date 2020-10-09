#include "stdafx.h"
#include "WindowBase.h"

/**
 * @brief   メインウインドウ
 */
class MainWindow
{
private:
protected:
    LPRECT m_pWindowRect;  //画面の大きさ
public:
    MainWindow();
    ~MainWindow();

    /**
     * @brief   このウインドウでのウインドウプロシージャ
     */
    const LRESULT LocalWindowProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

    /**
     * @brief   ウインドウを初期化
     */
    void Initialize(HINSTANCE hInst, LPCWSTR className);

    /**
     * @brief   ウインドウハンドル取得
     */
    HWND GetWindowHundle();

    /**
     * @brief   ウインドウサイズ取得
     */
    RECT GetWindowRect();
};