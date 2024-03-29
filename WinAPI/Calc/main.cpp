﻿#define _CRT_SECURE_NO_WARNINGS
#include<Windows.h>
#include<iostream>
#include"resource.h"

CONST CHAR g_sz_CLASSNAME[] = "MyCalc";
CONST INT g_i_START_X = 10;
CONST INT g_i_START_Y = 10;
CONST INT g_i_INTERVAL = 1;
CONST INT g_i_BUTTON_SIZE = 88;
CONST INT g_i_BUTTON_DOUBLE_SIZE = g_i_BUTTON_SIZE * 2 + g_i_INTERVAL;
CONST INT g_i_DISPLAY_WIDTH = (g_i_BUTTON_SIZE + g_i_INTERVAL) * 5 - g_i_INTERVAL;
CONST INT g_i_DISPLAY_HEIGHT = g_i_BUTTON_SIZE;
CONST INT g_i_BUTTON_START_X = g_i_START_X;
CONST INT g_i_BUTTON_START_Y = g_i_START_Y + g_i_DISPLAY_HEIGHT + g_i_INTERVAL;
CONST INT g_i_WINDOW_WIDTH = g_i_DISPLAY_WIDTH + g_i_START_X * 2 + 16;
CONST INT g_i_WINDOW_HEIGHT = g_i_DISPLAY_HEIGHT + g_i_START_Y * 2 + (g_i_BUTTON_SIZE + g_i_INTERVAL) * 4 + 42;

CONST CHAR* g_sz_arr_OPERATIONS[] = { "+", "-", "*", "/" };

CONST COLORREF g_clr_COLORS[][3] =
{
	{RGB(0, 0, 100), RGB(0, 0, 255), RGB(255, 0, 0)},
	{RGB(0, 100, 0), RGB(0, 255, 0), RGB(0, 255, 0)},
};


INT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
VOID SetSkin(HWND hwnd, CONST CHAR skin[]);

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpCmdLine, INT nCmdShow)
{
	//1) Регистрация класса окна:
	WNDCLASSEX wc;
	ZeroMemory(&wc, sizeof(wc));
	wc.cbSize = sizeof(wc);
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.style = 0;

	wc.hIcon = (HICON)LoadImage(hInstance, "calc.ico", IMAGE_ICON, LR_DEFAULTSIZE, LR_DEFAULTSIZE, LR_LOADFROMFILE);
	wc.hIconSm = (HICON)LoadImage(hInstance, "calc.ico", IMAGE_ICON, LR_DEFAULTSIZE, LR_DEFAULTSIZE, LR_LOADFROMFILE);
	wc.hCursor = LoadCursor(hInstance, IDC_ARROW);
	wc.hbrBackground = CreateSolidBrush(RGB(0, 0, 255));

	wc.hInstance = hInstance;
	wc.lpszMenuName = NULL;
	wc.lpszClassName = g_sz_CLASSNAME;
	wc.lpfnWndProc = (WNDPROC)WndProc;

	if (RegisterClassEx(&wc) == NULL)
	{
		MessageBox(NULL, "Class registration failed", "Error", MB_OK | MB_ICONERROR);
		return 0;
	}

	//2) Создание окна:
	HWND hwnd = CreateWindowEx
	(
		NULL,	//ExStyles
		g_sz_CLASSNAME,		//Class name
		g_sz_CLASSNAME,		//Window name
		WS_OVERLAPPEDWINDOW^WS_THICKFRAME^WS_MAXIMIZEBOX,//Window styles ^ - XOR
		CW_USEDEFAULT, CW_USEDEFAULT,//Position
		g_i_WINDOW_WIDTH, g_i_WINDOW_HEIGHT,//Size
		NULL,	//Parent window
		NULL,	//Menu
		hInstance,
		NULL
	);
	if (hwnd == NULL)
	{
		MessageBox(NULL, "Window creation failed", "Error", MB_OK | MB_ICONERROR);
		return 0;
	}
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
	CONST INT i_DISPLAY_BUFFER_SIZE = 256;
	static CHAR sz_display[i_DISPLAY_BUFFER_SIZE]{};

	static DOUBLE	a = 0;	//operands
	static DOUBLE	b = 0;	//operands
	static INT		operation;
	static BOOL		input = FALSE;
	static BOOL		operation_input = FALSE;
	static BOOL		in_default_state = TRUE;

	static CHAR		sz_skin[FILENAME_MAX] = "square_blue";

	//static COLORREF	clrDisplayBackground = RGB(0, 0, 100);
	//static COLORREF	clrWindowBackground = RGB(0, 0, 255);
	//static COLORREF	clrDiplayFont = RGB(255, 0, 0);
	static UINT colorref = 0;

	switch (uMsg)
	{
	case WM_CREATE:
	{
		HWND hEdit = CreateWindowEx
		(
			NULL, "Edit", "",
			WS_CHILD | WS_VISIBLE | WS_BORDER | ES_RIGHT,
			g_i_START_X, g_i_START_Y,
			g_i_DISPLAY_WIDTH, g_i_DISPLAY_HEIGHT,
			hwnd,
			(HMENU)IDC_EDIT,
			GetModuleHandle(NULL),
			NULL
		);
		AddFontResourceEx("fonts\\digital-7.ttf", FR_PRIVATE, 0);
		HFONT hFont = CreateFont
		(
			g_i_DISPLAY_HEIGHT - 2, g_i_DISPLAY_HEIGHT / 3,
			0,	//Escapement
			0,	//Orientation
			FW_BOLD,	//Weight
			FALSE, FALSE, FALSE, //Italic, Underline, Strikeout
			DEFAULT_CHARSET,
			OUT_TT_PRECIS,
			CLIP_DEFAULT_PRECIS,
			ANTIALIASED_QUALITY,
			FF_DONTCARE,
			"digital-7"
		);
		SendMessage(hEdit, WM_SETFONT, (WPARAM)hFont, TRUE);
		//		Digits:
		for (int i = 6; i >= 0; i -= 3)
		{
			for (int j = 0; j < 3; j++)
			{
				CHAR sz_digit[2] = "";
				sz_digit[0] = i + j + 49;
				CreateWindowEx
				(
					NULL, "Button", sz_digit,
					WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | BS_BITMAP,
					g_i_BUTTON_START_X + (g_i_BUTTON_SIZE + g_i_INTERVAL)*j,	//X-position
					g_i_BUTTON_START_Y + (g_i_BUTTON_SIZE + g_i_INTERVAL)*(3 - i / 3 - 1),//Y-position
					g_i_BUTTON_SIZE, g_i_BUTTON_SIZE,
					hwnd,
					(HMENU)(IDC_BUTTON_1 + i + j),
					GetModuleHandle(NULL),
					NULL
				);
			}
		}
		CreateWindowEx
		(
			NULL, "Button", "0",
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | BS_BITMAP,
			g_i_BUTTON_START_X,
			g_i_BUTTON_START_Y + (g_i_BUTTON_SIZE + g_i_INTERVAL) * 3,
			g_i_BUTTON_DOUBLE_SIZE, g_i_BUTTON_SIZE,
			hwnd,
			(HMENU)IDC_BUTTON_0,
			GetModuleHandle(NULL),
			NULL
		);
		CreateWindowEx
		(
			NULL, "Button", ".",
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			g_i_BUTTON_START_X + g_i_BUTTON_DOUBLE_SIZE + g_i_INTERVAL,
			g_i_BUTTON_START_Y + (g_i_BUTTON_SIZE + g_i_INTERVAL) * 3,
			g_i_BUTTON_SIZE, g_i_BUTTON_SIZE,
			hwnd,
			(HMENU)IDC_BUTTON_POINT,
			GetModuleHandle(NULL),
			NULL
		);
		////////////			Operations			/////////////////
		for (int i = 0; i < 4; i++)
		{
			CreateWindowEx
			(
				NULL,
				"Button",
				g_sz_arr_OPERATIONS[3 - i],
				WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
				g_i_BUTTON_START_X + (g_i_BUTTON_SIZE + g_i_INTERVAL) * 3,
				g_i_BUTTON_START_Y + (g_i_BUTTON_SIZE + g_i_INTERVAL)*i,
				g_i_BUTTON_SIZE, g_i_BUTTON_SIZE,
				hwnd,
				(HMENU)(IDC_BUTTON_SLASH - i),
				GetModuleHandle(NULL),
				NULL
			);
		}
		CreateWindowEx
		(
			NULL,
			"Button",
			"<-",
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			g_i_BUTTON_START_X + (g_i_BUTTON_SIZE + g_i_INTERVAL) * 4,
			g_i_BUTTON_START_Y,
			g_i_BUTTON_SIZE, g_i_BUTTON_SIZE,
			hwnd,
			(HMENU)IDC_BUTTON_BSP,
			GetModuleHandle(NULL),
			NULL
		);
		CreateWindowEx
		(
			NULL,
			"Button",
			"C",
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			g_i_BUTTON_START_X + (g_i_BUTTON_SIZE + g_i_INTERVAL) * 4,
			g_i_BUTTON_START_Y + g_i_BUTTON_SIZE + g_i_INTERVAL,
			g_i_BUTTON_SIZE, g_i_BUTTON_SIZE,
			hwnd,
			(HMENU)IDC_BUTTON_CLEAR,
			GetModuleHandle(NULL),
			NULL
		);
		CreateWindowEx
		(
			NULL,
			"Button",
			"=",
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			g_i_BUTTON_START_X + (g_i_BUTTON_SIZE + g_i_INTERVAL) * 4,
			g_i_BUTTON_START_Y + (g_i_BUTTON_SIZE + g_i_INTERVAL) * 2,
			g_i_BUTTON_SIZE, g_i_BUTTON_DOUBLE_SIZE,
			hwnd,
			(HMENU)IDC_BUTTON_EQUAL,
			GetModuleHandle(NULL),
			NULL
		);

		SetSkin(hwnd, "square_blue");

		RECT window_rect, client_rect;
		GetWindowRect(hwnd, &window_rect);
		GetClientRect(hwnd, &client_rect);
		using namespace std;
		cout << "Window rect:\t" << window_rect.left << window_rect.top << window_rect.right << window_rect.bottom << endl;
		cout << "Client rect:\t" << client_rect.left << client_rect.top << client_rect.right << client_rect.bottom << endl;
	}
	break;
	case WM_CTLCOLOREDIT:
	{
		HDC hdc = (HDC)wParam;
		SetBkMode(hdc, OPAQUE);
		//SetBkColor(hdc, clrDisplayBackground);
		//HBRUSH hBrush = CreateSolidBrush(clrWindowBackground);
		//SetTextColor(hdc, clrDiplayFont);
		SetBkColor(hdc, g_clr_COLORS[colorref][0]);
		HBRUSH hBrush = CreateSolidBrush(g_clr_COLORS[colorref][1]);
		SetTextColor(hdc, g_clr_COLORS[colorref][2]);
		SetClassLongPtr(hwnd, GCLP_HBRBACKGROUND, (LONG_PTR)hBrush);
		SendMessage(hwnd, WM_ERASEBKGND, wParam, 0);
		
		return (LRESULT)hBrush;
	}
	break;
	case WM_COMMAND:
	{
		HWND hEdit = GetDlgItem(hwnd, IDC_EDIT);
		SendMessage(hEdit, WM_GETTEXT, i_DISPLAY_BUFFER_SIZE, (LPARAM)sz_display);
		CHAR sz_symbol[2]{};
		if (LOWORD(wParam) >= IDC_BUTTON_0 && LOWORD(wParam) <= IDC_BUTTON_POINT)
		{
			if (input == FALSE)SendMessage(hEdit, WM_SETTEXT, 0, (LPARAM)"");
			sz_symbol[0] = LOWORD(wParam) - IDC_BUTTON_0 + 48;
			if (LOWORD(wParam) == IDC_BUTTON_POINT)
			{
				if (strchr(sz_display, '.'))break;
				sz_symbol[0] = '.';
			}
			strcat(sz_display, sz_symbol);
			SendMessage(hEdit, WM_SETTEXT, 0, (LPARAM)sz_display);
			input = TRUE;
		}
		if (LOWORD(wParam) >= IDC_BUTTON_PLUS && LOWORD(wParam) <= IDC_BUTTON_SLASH)
		{
			SendMessage(hEdit, WM_GETTEXT, i_DISPLAY_BUFFER_SIZE, (LPARAM)sz_display);
			if (input)b = atof(sz_display);

			if (in_default_state)a = b;
			in_default_state = FALSE;

			if (input && operation_input)SendMessage(hwnd, WM_COMMAND, LOWORD(IDC_BUTTON_EQUAL), 0);
			input = FALSE;
			operation = LOWORD(wParam);
			operation_input = TRUE;
		}
		if (LOWORD(wParam) == IDC_BUTTON_EQUAL)
		{
			SendMessage(hEdit, WM_GETTEXT, i_DISPLAY_BUFFER_SIZE, (LPARAM)sz_display);
			if (input)b = atof(sz_display);
			input = FALSE;
			switch (operation)
			{
			case IDC_BUTTON_PLUS:	a += b;	break;
			case IDC_BUTTON_MINUS:	a -= b; break;
			case IDC_BUTTON_ASTER:	a *= b;	break;
			case IDC_BUTTON_SLASH:	a /= b;	break;
			}
			operation_input = FALSE;
			sprintf(sz_display, "%g", a);
			SendMessage(hEdit, WM_SETTEXT, 0, (LPARAM)sz_display);
		}
		if (LOWORD(wParam) == IDC_BUTTON_CLEAR)
		{
			a = b = 0;
			operation = 0;
			input = FALSE;
			operation_input = FALSE;
			in_default_state = TRUE;
			sz_display[0] = 0;
			SendMessage(hEdit, WM_SETTEXT, 0, (LPARAM)sz_display);
		}
	}
	break;
	case WM_KEYDOWN:
	{
		if (GetKeyState(VK_CONTROL) < 0 && wParam == 0x38)SendMessage(hwnd, WM_COMMAND, IDC_BUTTON_ASTER, 0);
		else if (wParam >= 0x30 && wParam <= 0x39)
			SendMessage(hwnd, WM_COMMAND, LOWORD(wParam - 0x30 + 1000), 0);
		if (wParam >= 0x60 && wParam <= 0x69)
			SendMessage(hwnd, WM_COMMAND, LOWORD(wParam - 0x60 + 1000), 0);
		switch (wParam)
		{
		case VK_ADD:
		case VK_OEM_PLUS:	SendMessage(hwnd, WM_COMMAND, LOWORD(IDC_BUTTON_PLUS), 0);	break;
		case VK_OEM_MINUS:
		case VK_SUBTRACT:	SendMessage(hwnd, WM_COMMAND, LOWORD(IDC_BUTTON_MINUS), 0); break;
		case VK_MULTIPLY:	SendMessage(hwnd, WM_COMMAND, LOWORD(IDC_BUTTON_ASTER), 0); break;
		case VK_OEM_2:
		case VK_DIVIDE:		SendMessage(hwnd, WM_COMMAND, LOWORD(IDC_BUTTON_SLASH), 0); break;
		case VK_OEM_PERIOD:	SendMessage(hwnd, WM_COMMAND, LOWORD(IDC_BUTTON_POINT), 0); break;
		case VK_RETURN:		SendMessage(hwnd, WM_COMMAND, LOWORD(IDC_BUTTON_EQUAL), 0); break;
		case VK_ESCAPE:		SendMessage(hwnd, WM_COMMAND, LOWORD(IDC_BUTTON_CLEAR), 0); break;
		case VK_BACK:		SendMessage(hwnd, WM_COMMAND, LOWORD(IDC_BUTTON_BSP), 0); break;
		}
	}
	break;
	case WM_CONTEXTMENU:
	{
		HMENU hMainMenu = CreatePopupMenu();
		HMENU hSubMenu = CreatePopupMenu();
		InsertMenu(hMainMenu, 0, MF_BYPOSITION | MF_STRING, CM_EXIT, "Exit");
		InsertMenu(hMainMenu, 0, MF_BYPOSITION | MF_SEPARATOR, 0, NULL);
		InsertMenu(hMainMenu, 0, MF_BYPOSITION | MF_POPUP, (UINT_PTR)hSubMenu, "Skins");
		InsertMenu(hSubMenu, 0, MF_BYPOSITION | MF_STRING, CM_SQUARE_GREEN, "Square green");
		InsertMenu(hSubMenu, 0, MF_BYPOSITION | MF_STRING, CM_SQUARE_BLUE, "Square blue");

		BOOL item = TrackPopupMenuEx(hMainMenu, TPM_BOTTOMALIGN | TPM_LEFTALIGN | TPM_RETURNCMD, LOWORD(lParam), HIWORD(lParam), hwnd, NULL);
		switch (item)
		{
		case CM_SQUARE_BLUE:	strcpy(sz_skin, "square_blue");	colorref = item - 201;	break;
		case CM_SQUARE_GREEN:	strcpy(sz_skin, "square_green");colorref = item - 201;	break;
		case CM_EXIT:	DestroyWindow(hwnd);
		}
		SetSkin(hwnd, sz_skin);
		HDC hdc = GetDC(hwnd);
		SendMessage(hwnd, WM_CTLCOLOREDIT, (WPARAM)hdc, 0);
		SendMessage(GetDlgItem(hwnd, IDC_EDIT), WM_SETTEXT, 0, (LPARAM)"0");
		ReleaseDC(hwnd, hdc);
	}
	break;
	case WM_DESTROY:PostQuitMessage(0); break;
	case WM_CLOSE:	DestroyWindow(hwnd); break;
	default:		return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}
	return FALSE;
}

VOID SetSkin(HWND hwnd, CONST CHAR skin[])
{
	CHAR filename[FILENAME_MAX]{};
	for (int i = 0; i < 10; i++)
	{
		sprintf(filename, "ButtonsBMP\\%s\\button_%i.bmp", skin, i);
		HWND hButton = GetDlgItem(hwnd, IDC_BUTTON_0 + i);
		HBITMAP hBitmap = (HBITMAP)LoadImage
		(
			GetModuleHandle(NULL),
			filename, IMAGE_BITMAP,
			i == 0 ? g_i_BUTTON_DOUBLE_SIZE : g_i_BUTTON_SIZE, g_i_BUTTON_SIZE,
			LR_LOADFROMFILE
		);
		SendMessage(hButton, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)hBitmap);
	}
}