#include "stdafx.h"

class WindowBase
{
private:
protected:
    LPRECT m_pWindowRect;  //画面の大きさ
public:
    WindowBase();
    ~WindowBase();

    /**
     * @brief   このウインドウでのウインドウプロシージャ
     */
    virtual LRESULT LocalWindowProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

    /**
     * @brief   ウインドウを初期化
     */
    virtual void Initialize(HINSTANCE hInst, LPCWSTR className);

    /**
     * @brief   ウインドウハンドル取得
     */
    HWND GetWindowHundle();

    /**
     * @brief   ウインドウサイズ取得
     */
    RECT GetWindowRect();
};