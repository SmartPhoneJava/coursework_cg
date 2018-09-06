#include "stdafx.h"
#include "Scene.h"
#include "Vector.h"

/*
Проекция 3д объекта на плоскость
*/
//https://stackoverflow.com/questions/9605556/how-to-project-a-point-onto-a-plane-in-3d
void Scene::attach(Camera camera)
{
	std::list<Triangle> triangles;

	// цикл по объектам сцены
	for (Figure figure : objects)
	{
		// получаем список полигонов
		triangles = figure.getTriangles();

		// цикл по полигонам
		for (Triangle triangle : triangles)
		{
			// цикл по точкам треугольника
			for (int i = 0; i < 3; i++)
			{

			}
		}
	}
}