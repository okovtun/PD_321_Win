﻿#define _CRT_SECURE_NO_WARNINGS
#include<Windows.h>
#include<stdio.h>
#include"resource.h"

CONST CHAR* g_sz_VALUES[] = { "This", "is", "my", "first", "Combo", "Box" };

BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK DlgProcAddItem(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpCmdLine, INT nCmdShow)
{
	DialogBoxParam(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, DlgProc, 0);
	return 0;
}

BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_INITDIALOG:
	{
		HICON hIcon = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON_SPEAKER));
		SendMessage(hwnd, WM_SETICON, 0, (LPARAM)hIcon);
		//WM_ - Window Message

		HWND hCombo = GetDlgItem(hwnd, IDC_COMBO1);
		for (int i = 0; i < sizeof(g_sz_VALUES) / sizeof(g_sz_VALUES[0]); i++)
		{
			SendMessage(hCombo, CB_ADDSTRING, 0, (LPARAM)g_sz_VALUES[i]);
		}
		SendMessage(hCombo, CB_SETCURSEL, 0, 0);	//Сразу же выбираем нулевой элемент ComboBox
	}
	break;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDC_BUTTON_ADD:	DialogBoxParam(GetModuleHandle(NULL), MAKEINTRESOURCE(IDD_DIALOG_ADD_ITEM), hwnd, DlgProcAddItem, 0); break;
		case IDC_BUTTON_DELETE:
		{
			CHAR sz_buffer[FILENAME_MAX]{};
			CHAR sz_message[FILENAME_MAX]{};
			HWND hCombo = GetDlgItem(hwnd, IDC_COMBO1);
			int i = SendMessage(hCombo, CB_GETCURSEL, 0, 0);
			SendMessage(hCombo, CB_GETLBTEXT, i, (LPARAM)sz_buffer);
			sprintf(sz_message, "Вы действительно хотите удалить элемент №%i со значением \"%s\"?", i, sz_buffer);
			switch (MessageBox(hwnd, sz_message, "Вопрос", MB_YESNO | MB_ICONQUESTION))
			{
			case IDYES:	SendMessage(hCombo, CB_DELETESTRING, i, 0);
			case IDNO:	break;
			}
		}
		break;
		case IDOK:
		{
			HWND hCombo = GetDlgItem(hwnd, IDC_COMBO1);
			CHAR sz_buffer[MAX_PATH]{};
			CHAR sz_message[MAX_PATH]{};
			int i = SendMessage(hCombo, CB_GETCURSEL, 0, 0);	//Получаем номер выбранного элемента ComboBox
			SendMessage(hCombo, CB_GETLBTEXT, i, (LPARAM)sz_buffer);
			sprintf(sz_message, "Вы выбрали пункт %i со значением \"%s\".", i, sz_buffer);
			MessageBox(hwnd, sz_message, "Info", MB_OK | MB_ICONINFORMATION);
		}
		break;
		case IDCANCEL:EndDialog(hwnd, 0); break;
		}
		break;
	case WM_CLOSE:EndDialog(hwnd, 0);
	}
	return FALSE;
}
BOOL CALLBACK DlgProcAddItem(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_INITDIALOG:
		SetFocus(GetDlgItem(hwnd, IDC_EDIT_NEW_ITEM));
		break;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDOK:
		{
			CHAR sz_buffer[FILENAME_MAX] = {};
			HWND hEditAddItem = GetDlgItem(hwnd, IDC_EDIT_NEW_ITEM);
			SendMessage(hEditAddItem, WM_GETTEXT, FILENAME_MAX, (LPARAM)sz_buffer);
			HWND hParent = GetParent(hwnd);
			HWND hCombo = GetDlgItem(hParent, IDC_COMBO1);
			if (SendMessage(hCombo, CB_FINDSTRINGEXACT, -1, (LPARAM)sz_buffer) == CB_ERR)
				SendMessage(hCombo, CB_ADDSTRING, 0, (LPARAM)sz_buffer);
		}
		case IDCANCEL:EndDialog(hwnd, 0); break;
		}
		break;
	case WM_CLOSE:EndDialog(hwnd, 0);
	}
	return FALSE;
}