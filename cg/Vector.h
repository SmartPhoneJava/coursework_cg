#pragma once

#include "Point.h"

class Vector
{
private:

public:
	double x, y, z;

	/*������������ */
	Vector()
	{
		x = 0; y = 0; z = 0;
	}
	Vector(Point &p1, Point &p2) noexcept;
	Vector(double x1, double y1, double z1,
		double x2, double y2, double z2);
	Vector(double x, double y, double z);
	
	//������������ �����������
	Vector(Vector &&cut);

	Vector(const Vector &vector);

	Vector& operator=(const Vector& other) noexcept;

	Vector& operator=(Vector&& other)noexcept;

	// ���������
	static bool areEqual(const Vector &A, const Vector &B)noexcept;

	bool operator==(const Vector &B)noexcept;

	bool operator!=(const Vector &B)noexcept;

	// ���������

	static Vector vectorMultiplication(const Vector &vector1,
		const Vector &vector2) noexcept;

	static double scalarMultiplication(const Vector &vector1,
		const Vector &vector2) noexcept;

	Vector operator*(const Vector &v1) noexcept;

	Point asPoint();
};

