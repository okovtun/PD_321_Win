#define _CRT_SECURE_NO_WARNINGS
#include<Windows.h>
#include<cstdio>
#include"resource.h"

CONST CHAR g_sz_WINDOW_CLASS[] = "My first Window";

INT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpCmdLine, INT nCmdShow)
{
	//1) Регистрация класса окна:
	WNDCLASSEX wc;
	ZeroMemory(&wc, sizeof(wc));
	//cb - Count Bytes
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.style = 0;

	//wc.hIcon = LoadIcon(hInstance, IDI_APPLICATION);
	//wc.hIconSm = LoadIcon(hInstance, IDI_APPLICATION);
	wc.hIcon = (HICON)LoadImage(hInstance, "earth.ico", IMAGE_ICON, LR_DEFAULTSIZE, LR_DEFAULTSIZE, LR_LOADFROMFILE);
	wc.hIconSm = (HICON)LoadImage(hInstance, "moon.ico", IMAGE_ICON, LR_DEFAULTSIZE, LR_DEFAULTSIZE, LR_LOADFROMFILE);
	wc.hCursor = (HCURSOR)LoadImage(hInstance, "Background.ani", IMAGE_CURSOR, LR_DEFAULTSIZE, LR_DEFAULTSIZE, LR_LOADFROMFILE);
	//wc.hCursor = LoadCursor(hInstance, MAKEINTRESOURCE(IDC_CURSOR1));
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;

	wc.hInstance = hInstance;
	wc.lpszMenuName = NULL;
	wc.lpfnWndProc = (WNDPROC)WndProc;
	wc.lpszClassName = g_sz_WINDOW_CLASS;
	if (RegisterClassEx(&wc) == NULL)
	{
		MessageBox(NULL, "Class registration failed", "Error", MB_OK | MB_ICONERROR);
		return 0;
	}

	//2) Создание окна:
	//SM_ - System Metric;
	INT screen_width = GetSystemMetrics(SM_CXSCREEN);
	INT screen_height = GetSystemMetrics(SM_CYSCREEN);
	INT window_width = screen_width * 3 / 4;
	INT window_height = screen_height * 3 / 4;
	INT window_start_x = screen_width / 8;
	INT window_start_y = screen_height / 8;
	HWND hwnd = CreateWindowEx
	(
		NULL,	//ExStyles
		g_sz_WINDOW_CLASS,	//Class name
		g_sz_WINDOW_CLASS,	//Заголовок окна
		WS_OVERLAPPEDWINDOW,//Такой стиль задается главному окну. Этот стиль определяет ,
							//что у окна будет строка заголовка, кнопки управления окном, 
							//и маштабируемая граница.
		window_start_x, window_start_y,	//Положение окна на экране
		window_width, window_height,	//Положение окна на экране
		//CW_USEDEFAULT, CW_USEDEFAULT,	//Размер окна
		//CW_USEDEFAULT, CW_USEDEFAULT,	//Размер окна
		NULL,	//Родительское окно
		NULL,	//Для главного окна этот параметр задает меню,
				//а для дочернего окна - ID-ресурса дочернего окна (IDC_BUTTON_COPY, IDC_EDIT...)
		hInstance,
		NULL
	);
	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);

	//3) Запуск цикла сообщений:
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}

INT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CREATE:
		break;
	case WM_SIZE:
	case WM_MOVING:
	{
		CONST INT SIZE = 256;
		CHAR sz_title[SIZE]{};
		RECT rect;
		GetWindowRect(hwnd, &rect);
		sprintf(sz_title, "%s Position:%ix%i, Size: %ix%i", g_sz_WINDOW_CLASS, 
			rect.left, rect.top,
			rect.right-rect.left, rect.bottom-rect.top);
		SendMessage(hwnd, WM_SETTEXT, 0, (LPARAM)sz_title);
	}
	break;
	case WM_COMMAND:
		break;
	case WM_DESTROY:PostQuitMessage(0); break;
	case WM_CLOSE:	DestroyWindow(hwnd); break;
	default:		return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}
	return 0;
}