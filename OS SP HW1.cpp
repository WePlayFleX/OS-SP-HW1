#include <Windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(				//Task 4
	HINSTANCE hInst,
	HINSTANCE prevIst, 
	LPSTR cmdArgs,
	int typeShow)
{

	WNDCLASS wndclass;

	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInst;
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_CROSS);
	wndclass.hbrBackground = CreateSolidBrush(RGB(25, 51, 0));
	wndclass.lpszMenuName = NULL;
	wndclass.lpszClassName = TEXT("MyClass");
	wndclass.lpszClassName = L"MyClass";
	wndclass.style = NULL;
	wndclass.lpfnWndProc = WndProc;

	RegisterClass(&wndclass);

	HWND hwnd1;
	hwnd1 = CreateWindow(
		L"MyClass",
		L"WinApp",
		WS_OVERLAPPEDWINDOW,
		100, 100,
		800, 600,
		NULL,
		NULL,
		hInst,
		NULL);

	HWND hwnd2;
	hwnd2 = CreateWindow(
		L"MyClass",
		L"WinApp",
		WS_CLIPCHILDREN,
		150, 150,
		550, 500,
		NULL,
		NULL,
		hInst,
		NULL);

	HWND hwnd3;
	hwnd3 = CreateWindow(
		L"MyClass",
		L"WinApp",
		WS_CLIPCHILDREN,
		425, 350,
		250, 250,
		NULL,
		NULL,
		hInst,
		NULL);


	ShowWindow(hwnd1, typeShow);
	UpdateWindow(hwnd1);

	SetClassLong(hwnd2, GCL_HBRBACKGROUND, (LONG)CreateSolidBrush(RGB(255, 255, 0)));
	ShowWindow(hwnd2, typeShow);
	UpdateWindow(hwnd2);


	SetClassLong(hwnd3, GCL_HBRBACKGROUND, (LONG)CreateSolidBrush(RGB(192, 192, 192)));
	ShowWindow(hwnd3, typeShow);
	UpdateWindow(hwnd3);

	MSG msg;

	while (GetMessage(&msg, 0, 0, 0) == TRUE) {
		DispatchMessage(&msg);
	}

	return 0;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
	switch (message)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
	}

	return TRUE;
}
