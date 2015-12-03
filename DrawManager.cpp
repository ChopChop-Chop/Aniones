#include "DrawManager.h"
#include "Director.h"

CDrawManager::CDrawManager()
{
	_rtScreen.left = 0;
	_rtScreen.right = _rtScreen.left + 1280;
	_rtScreen.top = 0;
	_rtScreen.bottom = _rtScreen.top + 720;
}


CDrawManager::~CDrawManager()
{
}

bool CDrawManager::Init()
{
	if (!InitWin())
		return false;

	if (!InitD3D())
		return false;

	ShowWindow(_hWND, 5);
	UpdateWindow(_hWND);

	m_pCurCamera = new CCamera();
	m_pCurCamera->Init();

	return true;
}
bool CDrawManager::InitWin()
{

	WNDCLASSEX wc =
	{
		sizeof(WNDCLASSEX), CS_CLASSDC, MsgProc, 0L, 0L,
		GetModuleHandle(NULL), NULL, NULL, NULL, NULL,
		"framework", NULL
	};
	RegisterClassEx(&wc);

	int width = GetSystemMetrics(SM_CXFULLSCREEN);
	int height = GetSystemMetrics(SM_CYFULLSCREEN);

	_rtScreen.left = (width / 2) - (WINWIDTH / 2);
	_rtScreen.right = (width / 2) + (WINWIDTH / 2);
	_rtScreen.top = (height / 2) - (WINHEIGHT / 2);
	_rtScreen.bottom = (height / 2) + (WINHEIGHT / 2);

	// Create the application's window
	_hWND = CreateWindow("framework", "DirectXFramework",
		WS_OVERLAPPEDWINDOW, /*m_rtScreen.left*/100, /*m_rtScreen.top*/100, _rtScreen.right, _rtScreen.bottom,
		NULL, NULL, wc.hInstance, NULL);

	return true;
}
bool CDrawManager::InitD3D()
{
	// Create the D3D object.
	if (NULL == (_D3D = Direct3DCreate9(D3D_SDK_VERSION)))
		return false;

	// Set up the structure used to create the D3DDevice. Since we are now
	// using more complex geometry, we will create a device with a zbuffer.
	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));
	d3dpp.Windowed = TRUE;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
	d3dpp.EnableAutoDepthStencil = TRUE;
	d3dpp.AutoDepthStencilFormat = D3DFMT_D16;

	// Create the D3DDevice
	if (FAILED(_D3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, _hWND,
		D3DCREATE_MIXED_VERTEXPROCESSING,
		&d3dpp, &_device)))
	{
		return false;
	}

	// Turn on the zbuffer
	_device->SetRenderState(D3DRS_ZENABLE, TRUE);

	// Turn on ambient lighting 
	_device->SetRenderState(D3DRS_AMBIENT, 0xffffffff);

	D3DXCreateSprite(_device, &_sprite);

	return true;
}
void CDrawManager::SetMetrices()
{
	m_pCurCamera->Update();
}

void CDrawManager::setCamera(CCamera* a_pCamera)
{
	m_pCurCamera = a_pCamera;
}
void CDrawManager::PreRender()
{
	_device->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER,
		D3DCOLOR_XRGB(0, 0, 255), 1.0f, 0);
	_device->BeginScene();
}
void CDrawManager::Draw2D(LPDIRECT3DTEXTURE9 a_lpTexture, RECT a_rtSrc, D3DXVECTOR3 a_vCenter, D3DXVECTOR3 a_vPos, D3DCOLOR a_Color)
{
	_sprite->Begin(D3DXSPRITE_ALPHABLEND);
	
	if (a_lpTexture == NULL)
	{
		MessageBox(_hWND, "Texture Null", "Texture Null", MB_OK);
		PostQuitMessage(0);
		return;
	}
	_sprite->Draw(a_lpTexture, NULL, &a_vCenter, &a_vPos, a_Color);
	
	_sprite->End();
}
void CDrawManager::Draw3D(LPDIRECT3DTEXTURE9 a_Tex, D3DXMATERIAL a_Mat)
{
}
void CDrawManager::PostRender()
{
	_device->EndScene();
	_device->Present(0, 0, 0, 0);
}
void CDrawManager::Release()
{
	//SAFE_RELEASE(_mesh);
	//SAFE_RELEASE(_sprite);
	//SAFE_RELEASE(_device);
	//SAFE_RELEASE(_D3D);
}