#include "stdafx.h"
#include "Scene.h"
#include "Vector.h"

/*
�������� 3� ������� �� ���������
*/
//https://stackoverflow.com/questions/9605556/how-to-project-a-point-onto-a-plane-in-3d
void Scene::attach(Camera camera)
{
	std::list<Triangle> triangles;

	// ���� �� �������� �����
	for (Figure figure : objects)
	{
		// �������� ������ ���������
		triangles = figure.getTriangles();

		// ���� �� ���������
		for (Triangle triangle : triangles)
		{
			// ���� �� ������ ������������
			for (int i = 0; i < 3; i++)
			{

			}
		}
	}
}