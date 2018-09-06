#include "stdafx.h"
#include "Graphics.h"

// Рисование отрезка по двум точкм, состоящим из 2 координат
void drawLine(HDC hdc, int X1, int Y1,
	int X2, int Y2, DWORD color)
{
	HPEN hPen = CreatePen(PS_SOLID, 1, color);
	
	SelectObject(hdc, hPen);

	MoveToEx(hdc, X1, Y1, NULL);
	LineTo(hdc, X2, Y2);

	DeleteObject(hPen);
}

void drawEllipse(HDC hdc, int X,
	int Y, int rad, DWORD color)
{
	HPEN hPen = CreatePen(PS_SOLID, 1, color);

	SelectObject(hdc, hPen);
	Ellipse(hdc, X - rad, Y - rad, X + rad, Y + rad);
	DeleteObject(hPen);
}