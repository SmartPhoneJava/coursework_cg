#pragma once
#include "Scene.h"
#include "Triangle.h"
#include "Vector.h"

class Figure
{
private:
	
public:
	// 478
	int id; //Числовой идентификатор объекта
	static int next_id; // айди следующего элемента
	int state; // Состояние объекта
	int attr; // Атрибуты объекта

	float avg_radius; // Средний радиус объекта для обнаружения столкновений
	float max_radius; // Максимальный радиус объекта

	Point center; // Положение объекта в мировых координатах
	Vector dir; // Единичный вектор направления
	Vector ux, uy, uz;
	// Локальные оси для отслеживания ориентации объекта (обновляются
	// автоматически при вызове функции поворота)

	std::list<Point> vertices_local; // список вершин с локальными координатами
	std::list<Point> vertices_trans; // список вершин с преобразованными мировыми координатами
	int vertices_size; // размер списков
	std::list<Triangle> polygons; // список полигонов	int polygons_size; // количество полигонов
};

// разобраться, как упорядочивать и проверять упорядочивание через список вершин
// Предлагается через полярные координаты
// http://www.gamedev.ru/code/forum/?id=40728
// http://rsdn.org/forum/alg/3461405.hot