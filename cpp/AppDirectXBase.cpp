#include "AppDirectXBase.h"

AppDirectXBase::AppDirectXBase()
{
}

AppDirectXBase::~AppDirectXBase()
{
}

HRESULT AppDirectXBase::Run(HINSTANCE hInst){
    std::cout << "aaa";
    return S_OK;
}

/**
 * @brief   ウインドウクラスを登録する関数
 * @return  成功:S_OK   失敗:S_FALSE
 */
HRESULT AppDirectXBase::RegistWndClass(){
    WNDCLASSEX wndClass={};
    
    //ウインドウクラス内容
    wndClass.cbSize         =sizeof(WNDCLASSEX);
    wndClass.style          =CS_HREDRAW | CS_VREDRAW        //ウインドウ拡縮があったら再描画
    wndClass.cbClsExtra     =0;                             //ウインドウクラス構造体に割り当てる補足バイト数
    wndClass.cbWndExtra     =0;                             //ウインドウインスタンスに割り当てる補足バイト数
    wndClass.hbrBackground  =COLOR_BACKGROUND;              //背景色    今回は壁紙つまり透過
    wndClass.hCursor        =LoadCursor( NULL, IDC_ARROW ); //マウスカーソルのハンドル LoadCursorを使うといい
    wndClass.hInstance      =m_hInst;                       //インスタンスハンドル
    wndClass.lpfnWndProc    =WNDPROC;                        //ウインドウのメッセージを処理するコールバック関数のポインタ
    wndClass.lpszClassName  ="更級のウインドウ";              //ウインドウ上部の名前

    if(!RegisterClassEx(wndClass)){
        return S_FALSE;
    }

    return S_OK;
}

/**
 * @brief   ウインドウ作成関数
 * @return  成功:S_OK   失敗:S_FALSE
 */
HRESULT AppDirectXBase::CreateMainWindow(){
    

    return S_OK;
}

/**
 * @brief   諸々の初期化
 * @return  成功:S_OK   失敗:S_FALSE
 */
HRESULT AppDirectXBase::Initialize(){
    return S_OK;
}

/**
 * @brief   メインループ
 * @return  成功:S_OK   失敗:S_FALSE
 */
HRESULT AppDirectXBase::Update(){
    return S_OK;
}

/**
 * @brief   解放
 * @return  成功:S_OK   失敗:S_FALSE
 */
HRESULT AppDirectXBase::Release(){
    return S_OK;
}