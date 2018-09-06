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
Point::Point() // конструктор класса
{
	x = 0;
	y = 0;
	z = 0;
}

Point::Point(double x, double y, double z) // конструктор класса
{
	x = 0;
	y = 0;
	z = 0;
}

Point::Point(Point *point) // конструктор класса
{
	x = point->x;
	y = point->y;
	z = point->z;
}

// конструктор копирования
Point::Point(const Point &point)
{
	x = point.x;
	y = point.y;
	z = point.z;
}

Point::Point(Point &&point) noexcept
{
	x = point.x;
	y = point.y;
	z = point.z;
}

Point& Point::operator=(const Point& other) noexcept
{
	x = other.x;
	y = other.y;
	z = other.z;
	return *this;
}

Point& Point::operator=(Point&& other)noexcept
{
	x = other.x;
	y = other.y;
	z = other.z;
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

double Point::worldX(Figure f) const noexcept
{
	return x + f.center.x;
}

double Point::worldY(Figure f) const noexcept
{
	return y + f.center.y;
}

double Point::worldZ(Figure f) const noexcept
{
	return z + f.center.z;
}