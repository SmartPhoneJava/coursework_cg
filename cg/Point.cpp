#include "stdafx.h"
#include "Point.h"
#include "Graphics.h"
#include <iostream>

/*
void Point::setX(Point *point)noexcept
{
	this->x = point->x;
}

void Point::setX(const Point &point)noexcept
{
	this->x = point.x;
}

void Point::setX(double x)noexcept
{
	this->x = x;
}

void Point::setY(Point *point)noexcept
{
	this->y = point->y;
}

void Point::setY(const Point &point)noexcept
{
	this->y = point.y;
}

void Point::setY(double y)noexcept
{
	this->y = y;
}

void Point::setZ(Point *point)noexcept
{
	this->z = point->z;
}

void Point::setZ(const Point &point)noexcept
{
	this->z = point.z;
}

void Point::setZ(double z)noexcept
{
	this->z = z;
}

double Point::getX() const noexcept
{
	return this->x;
}

double Point::getY() const noexcept
{
	return this->y;
}

double Point::getZ() const noexcept
{
	return this->z;
}
*/
void Point::init(double a, double b, double c, double d)
{
	x = a;
	y = b;
	z = c;
	w = d;
}

void Point::init(const Point& p)
{
	init(p.x, p.y, p.z, p.w);
}

void Point::create()
{
	init(0, 0, 0, 1);
}

Point::Point() // конструктор класса
{
	create();
}

Point::Point(double a, double b, double c, double d) // конструктор класса
{
	init(a, b, c, d);
}

Point::Point(MoveOptions& opt)
{
	init(opt[0], opt[1], opt[2], 1);
}

Point::Point(Point *point) // конструктор класса
{
	init(*point);
}

// конструктор копирования
Point::Point(const Point &point)
{
	init(point);
}

Point::Point(Point &&point) noexcept
{
	init(point);
}

Point& Point::operator=(const Point& other) noexcept
{
	init(other);
	return *this;
}

Point& Point::operator=(Point&& other)noexcept
{
	init(other);
	return *this;
}

bool Point::isEqual(const Point &B)noexcept
{
	return((this->x == B.x) && (this->y == B.y) && (this->z == B.z));
}

bool Point::operator==(const Point& other)noexcept
{
	return isEqual(other);
}

bool Point::operator!=(const Point& other)noexcept
{
	return !isEqual(other);
}

double Point::localX() const noexcept
{
	return x;
}
double Point::localY() const noexcept
{
	return y;
}
double Point::localZ() const noexcept
{
	return z;
}

double Point::worldX(Object f) const noexcept
{
	return x + f.center.x;
}

double Point::worldY(Object f) const noexcept
{
	return y + f.center.y;
}

double Point::worldZ(Object f) const noexcept
{
	return z + f.center.z;
}