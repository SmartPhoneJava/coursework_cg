#pragma once
#include "Scene.h"
#include "Triangle.h"
#include "Vector.h"

class Figure
{
private:
	
public:
	// 478
	int id; //�������� ������������� �������
	static int next_id; // ���� ���������� ��������
	int state; // ��������� �������
	int attr; // �������� �������

	float avg_radius; // ������� ������ ������� ��� ����������� ������������
	float max_radius; // ������������ ������ �������

	Point center; // ��������� ������� � ������� �����������
	Vector dir; // ��������� ������ �����������
	Vector ux, uy, uz;
	// ��������� ��� ��� ������������ ���������� ������� (�����������
	// ������������� ��� ������ ������� ��������)

	std::list<Point> vertices_local; // ������ ������ � ���������� ������������
	std::list<Point> vertices_trans; // ������ ������ � ���������������� �������� ������������
	int vertices_size; // ������ �������
	std::list<Triangle> polygons; // ������ ���������	int polygons_size; // ���������� ���������
};

// �����������, ��� ������������� � ��������� �������������� ����� ������ ������
// ������������ ����� �������� ����������
// http://www.gamedev.ru/code/forum/?id=40728
// http://rsdn.org/forum/alg/3461405.hot