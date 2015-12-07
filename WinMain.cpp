#include "Header.h"
#include "Director.h"

INT WINAPI wWinMain(HINSTANCE hInst, HINSTANCE, LPWSTR, INT)
{
	UNREFERENCED_PARAMETER(hInst);

	AllocConsole();
	freopen("CONIN$", "r", stdin);
	freopen("CONOUT$", "w", stdout);
	freopen("CONOUT$", "w", stderr);


	// °ÔÀÓ
	if (!CDIRECTOR->Init())
	{
		MessageBox(NULL, "InitError", "Error", MB_OK);
		std::cout << "Director Initialize Error" << std::endl;
		return -1;
	}
	CDIRECTOR->Run();
	CDIRECTOR->Release();
	////

	FreeConsole(); // Release
	
	return 0;
}