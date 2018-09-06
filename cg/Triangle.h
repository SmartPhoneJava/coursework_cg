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

	Object *figure; // ��������� �� ������ ������
	int indexes[3]; // 3 ������� ��� ������ 3-�� �����

	int state; // ��������� �������� - ��������, ���������� � �.�.
	int attr; // ���������� �������� - ������������ �� ���� ��� ������, ����� ��� ������������, ����������� �������� ����
	DWORD color; // ����

	/*������������ */
	Triangle(const Point &p1, const Point &p2, const Point &p3);
	Triangle(const Triangle &triangle);
	~Triangle();

	Triangle& operator=(const Triangle& other) noexcept;

	Triangle& operator=(Triangle&& other)noexcept;

	bool isEqual(const Triangle &B)noexcept;

	bool operator==(const Triangle &B)noexcept;

	bool operator!=(const Triangle &B)noexcept;
};