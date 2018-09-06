#pragma once
#include "Point.h"
#include <list>
#include "Object.h"

class Triangle
{
private:

	void copy(const Triangle& triangle) noexcept;

	void destroy() noexcept;

public:
	//std::list<Point> points;

	Object *figure; // указатель на список вершин
	int indexes[3]; // 3 индекса для выбора 3-ех точек

	int state; // состояние полигона - активный, отсеченный и т.д.
	int attr; // физические свойства - представляет из себя ряд флагов, таких как прозрачность, способность отражать цвет
	DWORD color; // цвет

	/*Конструкторы */
	Triangle(const Point &p1, const Point &p2, const Point &p3);
	Triangle(const Triangle &triangle);
	~Triangle();

	Triangle& operator=(const Triangle& other) noexcept;

	Triangle& operator=(Triangle&& other)noexcept;

	bool isEqual(const Triangle &B)noexcept;

	bool operator==(const Triangle &B)noexcept;

	bool operator!=(const Triangle &B)noexcept;
};