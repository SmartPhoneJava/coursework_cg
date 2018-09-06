#pragma once
#include "Point.h"
#include "Vector.h"
#include <iostream>

#define AXIS_X 101
#define AXIS_Y 102
#define AXIS_Z 103
#define NOTHING 0

#define SIZE 4
class Options
{
public:
	double params[3];
	bool inverse;
	Options() {};
	Options(double a, double b, double c)
	{
		params[0] = a;
		params[1] = b;
		params[2] = c;
		inverse = false;
	};

	double& operator[] (int index)
	{
		if (index > 2)
		{
			std::cout << "����� Options �� ��������� ��������� � �������� ������� ���������� � �������� ������ 2 ";
			return params[2];
		}
		return params[index];
	}
};

/*
param[0/1/2] - ����� �� x/y/z
*/
class MoveOptions : public Options
{
public:
	MoveOptions()
	{
		params[0] = 0;
		params[1] = 0;
		params[2] = 0;
		inverse = false;
	}

	MoveOptions(Point p)
	{
		params[0] = p.x;
		params[1] = p.y;
		params[2] = p.z;
		inverse = false;
	}
	MoveOptions(Point p, bool in)
	{
		params[0] = p.x;
		params[1] = p.y;
		params[2] = p.z;
		inverse = in;
	}
}; 

class ScaleOptions : public Options
{
public:
	ScaleOptions()
	{
		params[0] = 1;
		params[1] = 1;
		params[2] = 1;
		inverse = false;
	}
};
/*
param[0/1/2] - ����������� ��������������� x/y/z
*/


struct RotateOptions : public Options
{
public:
	RotateOptions()
	{
		params[0] = NOTHING;
		params[1] = 0;
		params[2] = 0;
		inverse = false;
	}
	RotateOptions(int choose, double angle, bool in = false)
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
			std::cout << "������� �������������� ��� ��������" << choose;
			params[1] = 0;
		}
		inverse = in;
	}
};
/*
param[0] - ����� ���, x/y/z
param[1] - ���� ��������
*/

class Action
{
public:
	virtual Vector apply(const Vector &v, Options &opt) = 0;
};

class Move : public Action
{
	Vector apply(const Vector &v, Options &opt) override;
};

class Rotate : public Action
{
private:
	Vector rotateX(const Vector &v, double angle);
	Vector rotateY(const Vector &v, double angle);
	Vector rotateZ(const Vector &v, double angle);
public:
	Vector apply(const Vector &v, Options &opt) override;
};

class Scale : public Action
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