#pragma once
#include "stdafx.h"
#include "Figure.h"
#include "Camera.h"
#include <list>

// плоскость
class Scene
{
private:
public:
	HDC hdc;
	double A, B, C, D;
	std::list<Figure> objects;

	Scene();
	Scene(HDC hdc);
	void clean();
	void attach(Camera camera);
};