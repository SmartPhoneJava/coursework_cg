#pragma once
#include "Point.h"
#include "Vector.h"
#include <iostream>

#define SIZE 4
class Options
{
public:
	double params[3];
	Options() {};
	Options(double a, double b, double c)
	{
		params[0] = a;
		params[1] = b;
		params[2] = c;
	};

	double& operator[] (int index)
	{
		if (index > 2)
		{
			std::cout << "Класс Options не допускает обращение к элементу массива параметров с индексом больше 2 ";
			return params[2];
		}
		return params[index];
	}
};

/*
param[0/1/2] - сдвиг по x/y/z
*/
class Move_options : Options
{
	Move_options()
	{
		params[0] = 0;
		params[1] = 0;
		params[2] = 0;
	}
}; 

class Scale_options : Options
{
	Scale_options()
	{
		params[0] = 1;
		params[1] = 1;
		params[2] = 1;
	}
};
/*
param[0/1/2] - коэффициент масштабирования x/y/z
*/

#define AXIS_X 101
#define AXIS_Y 102
#define AXIS_Z 103
#define NOTHING 0

struct Rotate_options : Options
{
	Rotate_options()
	{
		params[0] = NOTHING;
		params[1] = 0;
		params[2] = 0;
	}
	Rotate_options(int choose, double angle)
	{
		params[2] = 0;
		params[1] = angle;
		params[0] = NOTHING;
		switch (choose)
		{
		case AXIS_X:
		{
			params[0] = AXIS_X;
			break;
		}
		case AXIS_Y:
		{
			params[0] = AXIS_Y;
			break;
		}
		case AXIS_Z:
		{
			params[0] = AXIS_Z;
			break;
		}
		default:
			std::cout << "Указана несуществующая ось поворота" << choose;
			params[1] = 0;
		}
	}
};
/*
param[0] - выбор оси, x/y/z
param[1] - угол поворота
*/

class Action
{
public:
	virtual Vector apply(const Vector &v, Options &opt) = 0;
};

class Move : Action
{
	Vector apply(const Vector &v, Options &opt) override;
};

class Rotate : Action
{
private:
	Vector rotateX(const Vector &v, double angle);
	Vector rotateY(const Vector &v, double angle);
	Vector rotateZ(const Vector &v, double angle);
public:
	Vector apply(const Vector &v, Options &opt) override;
};

class Scale : Action
{
	Vector apply(const Vector &v, Options &opt) override;
};

class Transformation
{
public:
	static Vector apply(const Vector &vector,
		Action &act, Options &opt);
	static Point apply(Point &point,
		Action &act, Options &opt);
};

class Matrix
{
public:
	double matrix[SIZE][SIZE];
	Matrix();
	Matrix(const Matrix &a);
	Matrix(Matrix &&a);
	Matrix(double m[SIZE][SIZE]);
	Matrix(Vector a);

	Vector asVector() const;
	
	static Matrix multiplicate(Matrix a, Matrix b);
	static Vector multiplicate(Vector v, Matrix m);
};