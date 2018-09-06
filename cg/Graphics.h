#pragma once
#include <Windows.h>

#define RED RGB(255, 0, 0)
#define GREEN RGB(0, 255, 0)
#define BLUE RGB(0, 0, 255)
#define BLACK RGB(0, 0, 0)
#define WHITE RGB(255, 255, 255)

void drawLine(HDC hdc, int X1, int Y1,
	int X2, int Y2, DWORD color);

void drawEllipse(HDC hdc, int X,
	int Y, int rad, DWORD color);