#pragma once
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "Transformation.h"
#include "Object.h"

class Loader
{
	// Эта небольшая вспомогательная функция считывает
	// поочередно по одной строке из файла в формате PLG и
	// пропускает комментарии и пустые строки. Функция
	// возвращает значащие строки обрабатываемого файла или
	// значение NULL, если этот файл пуст
	char *getLine(char* buffer, int maxLength,
		FILE *f)
	{		int length, i;		while (1)		{			if (!fgets(buffer, maxLength, f))				return NULL;			// Удаляем пробелы			for (length = strlen(buffer), i = 0;				isspace(buffer[i]); i++) {			};			// Проверяем не являеится ли строка пустой			if ((i >= length) || (buffer[i] == '#'))				continue;			// Теперь понятно, что считанная строка 			// является значащей			return (&buffer[i]);		}
	}

	void message(char *filename, const char* text,
		const int err)
	{
		std::cout << "\n Ошибка в файле " <<
			filename << " при попытке " << text <<
			". Код ошибки:" << err;
	}

	// посылать объект как Object obj; &obj;
	int load(Object *object, char* filename, ScaleOptions sop,
		RotateOptions rop, MoveOptions mop)
	{
		FILE *f;
		char buffer[256];
		char *token_string; // указатель на лексему
		
		// Инициализация объекта
		object->state = OBJECT_STATE_ACTIVE | OBJECT_STATE_VISIBLE;
		object->center = Point(mop);

		// Открываем файл
		if (!(f = fopen(filename, "r")))
		{
			message(filename, "открыть файл",
				ERROR_NO_FILE);
			return ERROR_NO_FILE;
		}

		// Извлекаем первую лексему, которая должна быть
		// дескриптором объекта
		if (!(token_string = getLine(buffer, 255, f)))
		{
			message(filename, "получить дескриптор",
				ERROR_WRONG_DESCRIPTOR);
			return ERROR_WRONG_DESCRIPTOR;
		}

		// Анализируем дескриптор
		sscanf(token_string, "%s %d %d",
			object->name,
			&object->vertices_size,
			&object->polygons_size);
		
		double v_x, v_y, v_z;
		Scale scale;
		// Загружаем список вершин
		for (int v = 0; v < object->vertices_size; v++)
		{
			//Извлекаем очередную вершину
			if (!(token_string - getLine(buffer, 255, f)))
			{
				message(filename, "загрузить вершину",
					ERROR_WRONG_VERTEX);
				return ERROR_WRONG_VERTEX;
			}


			// Анализируем вершину
			sscanf(token_string, "%f %f %f",
				&v_x, &v_y, &v_z);

			// Помещаем в массив вершин объекта
			object->vertex_local.push_back(
				Point(v_x, v_y, v_z, 1));

			// Выполняем масштабирование вершины
			Transformation::apply(object->vertex_local.back(), scale, sop);
		}
	}
};