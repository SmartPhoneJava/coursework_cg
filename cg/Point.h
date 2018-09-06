#pragma once
#include "Resource.h"
#include "Figure.h"

#define NO_POINT 0

class Point
{
public:
	double x, y, z;

	/*Конструкторы */
	Point();

	Point(Point *p);
	Point(const Point &point);
	Point(double x, double y, double z);

	double localX() const noexcept;
	double localY() const noexcept;
	double localZ() const noexcept;

	double worldX(Figure f) const noexcept;
	double worldY(Figure f) const noexcept;
	double worldZ(Figure f) const noexcept;

	Point(Point &&point) noexcept;

	Point& operator=(const Point& other) noexcept;

	Point& operator=(Point&& other)noexcept;

	bool isEqual(const Point &B)noexcept;

	bool operator==(const Point& other)noexcept;

	bool operator!=(const Point& other)noexcept;
};