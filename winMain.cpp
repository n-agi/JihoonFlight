#include "Global.h"
#include "CTitleScene.h"
#include <d3d9.h>

LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

VOID Cleanup();
VOID Init();
VOID Render();
VOID Update();
void CenterWindow(HWND hwnd);
HRESULT InitD3D( HWND hWnd )
{
    if( NULL == ( g_pD3D = Direct3DCreate9( D3D_SDK_VERSION ) ) )
        return E_FAIL;

    D3DPRESENT_PARAMETERS d3dpp;
    ZeroMemory( &d3dpp, sizeof( d3dpp ) );
    d3dpp.Windowed = TRUE;
    d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
    d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;

    if( FAILED( g_pD3D->CreateDevice( D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd,
                                      D3DCREATE_SOFTWARE_VERTEXPROCESSING,
                                      &d3dpp, &g_pd3dDevice ) ) )
    {
        return E_FAIL;
    }

	Init();
    return S_OK;
}
int WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR, int){
	// Register the window class.
	WNDCLASSEX wc = { sizeof(WNDCLASSEX), CS_CLASSDC, WndProc, 0L, 0L, 
	GetModuleHandle(NULL), NULL, NULL, NULL, NULL,
	L"전지훈 플라이트", NULL };

	g_pd3dDevice = NULL;
	g_pD3D = NULL;
	g_pSprite = NULL;

	RegisterClassEx( &wc );

	// Create the application's window.
	HWND hWnd = CreateWindow( L"전지훈 플라이트", L"전지훈 플라이트", 
	WS_THICKFRAME, 100, 100, 400, 600,
	GetDesktopWindow(), NULL, wc.hInstance, NULL );

	if (SUCCEEDED(InitD3D(hWnd))){
		CenterWindow(hWnd);
		ShowWindow(hWnd, SW_SHOWDEFAULT);
		UpdateWindow(hWnd);
		MSG msg;
		msg.message=WM_NULL;
		bool go=false;
		PeekMessage( &msg, NULL, 0U, 0U, PM_NOREMOVE );
		
		SetTimer( hWnd, NULL, 17, NULL );

		while ( msg.message != WM_QUIT ){
			go = PeekMessage( &msg, NULL, 0U, 0U, PM_REMOVE ) !=0;
			if(go)
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
			else
			{
				Render();//여기다 랜더
			}
		}

	}

	Cleanup();
	UnregisterClass(L"전지훈 플라이트",wc.hInstance);
	
	return 0;
}

LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam){
	switch(msg){
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	case WM_TIMER:
		Update();
		return 0;
	case WM_KEYDOWN:
		if(wParam == 27)
			PostQuitMessage(0);
		return 0;
		/*	
	case WM_PAINT:
		Render();
		ValidateRect(hWnd, NULL);
		return 0;
		*/
	}
	return DefWindowProc(hWnd, msg, wParam, lParam);
}

VOID Init()
{
	D3DXCreateSprite( g_pd3dDevice , &g_pSprite );
	scm = new CSceneManager();
	scm->changeScene ( new CTitleScene() );
}

VOID Update()
{
	scm->update();
}

VOID Render()
{
    if( NULL == g_pd3dDevice )
        return;


    // Clear the backbuffer to a blue color
    g_pd3dDevice->Clear( 0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB( 0, 0, 0 ), 1.0f, 0 );

    // Begin the scene
    if( SUCCEEDED( g_pd3dDevice->BeginScene() ) )
    {
        // Rendering of scene objects can happen here
		scm->render();
        // End the scene
        g_pd3dDevice->EndScene();
    }

    // Present the backbuffer contents to the display
    g_pd3dDevice->Present( NULL, NULL, NULL, NULL );
}


VOID Cleanup()
{
    if( g_pd3dDevice != NULL )
        g_pd3dDevice->Release();

    if( g_pD3D != NULL )
        g_pD3D->Release();

	clearTexture();
	delete(scm);
}

void CenterWindow(HWND hWnd)
{
 RECT wrt ;
 LONG iX, iY, iWidth, iHeight ;

 GetWindowRect(hWnd,&wrt) ;
 iWidth = wrt.right - wrt.left ;
 iHeight = wrt.bottom - wrt.top ;
 iX = LONG((GetSystemMetrics(SM_CXSCREEN) - iWidth) / 2) ;
 iY = LONG((GetSystemMetrics(SM_CYSCREEN) - iHeight) / 2) ;
 MoveWindow(hWnd,iX,iY,iWidth,iHeight,TRUE) ;
}
