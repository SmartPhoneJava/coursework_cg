#pragma once
#include "Point.h"

class Camera
{
public:
	Point point; // ���������� ������
	// ����������� ������ 431
	double ang_x, ang_y, ang_z;

	double fov; // field_of_view ���� ������
};