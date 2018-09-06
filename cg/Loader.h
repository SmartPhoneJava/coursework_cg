#pragma once
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "Transformation.h"
#include "Object.h"

class Loader
{
	// ��� ��������� ��������������� ������� ���������
	// ���������� �� ����� ������ �� ����� � ������� PLG �
	// ���������� ����������� � ������ ������. �������
	// ���������� �������� ������ ��������������� ����� ���
	// �������� NULL, ���� ���� ���� ����
	char *getLine(char* buffer, int maxLength,
		FILE *f)
	{		int length, i;		while (1)		{			if (!fgets(buffer, maxLength, f))				return NULL;			// ������� �������			for (length = strlen(buffer), i = 0;				isspace(buffer[i]); i++) {			};			// ��������� �� ��������� �� ������ ������			if ((i >= length) || (buffer[i] == '#'))				continue;			// ������ �������, ��� ��������� ������ 			// �������� ��������			return (&buffer[i]);		}
	}

	void message(char *filename, const char* text,
		const int err)
	{
		std::cout << "\n ������ � ����� " <<
			filename << " ��� ������� " << text <<
			". ��� ������:" << err;
	}

	// �������� ������ ��� Object obj; &obj;
	int load(Object *object, char* filename, ScaleOptions sop,
		RotateOptions rop, MoveOptions mop)
	{
		FILE *f;
		char buffer[256];
		char *token_string; // ��������� �� �������
		
		// ������������� �������
		object->state = OBJECT_STATE_ACTIVE | OBJECT_STATE_VISIBLE;
		object->center = Point(mop);

		// ��������� ����
		if (!(f = fopen(filename, "r")))
		{
			message(filename, "������� ����",
				ERROR_NO_FILE);
			return ERROR_NO_FILE;
		}

		// ��������� ������ �������, ������� ������ ����
		// ������������ �������
		if (!(token_string = getLine(buffer, 255, f)))
		{
			message(filename, "�������� ����������",
				ERROR_WRONG_DESCRIPTOR);
			return ERROR_WRONG_DESCRIPTOR;
		}

		// ����������� ����������
		sscanf(token_string, "%s %d %d",
			object->name,
			&object->vertices_size,
			&object->polygons_size);
		
		double v_x, v_y, v_z;
		Scale scale;
		// ��������� ������ ������
		for (int v = 0; v < object->vertices_size; v++)
		{
			//��������� ��������� �������
			if (!(token_string - getLine(buffer, 255, f)))
			{
				message(filename, "��������� �������",
					ERROR_WRONG_VERTEX);
				return ERROR_WRONG_VERTEX;
			}


			// ����������� �������
			sscanf(token_string, "%f %f %f",
				&v_x, &v_y, &v_z);

			// �������� � ������ ������ �������
			object->vertex_local.push_back(
				Point(v_x, v_y, v_z, 1));

			// ��������� ��������������� �������
			Transformation::apply(object->vertex_local.back(), scale, sop);
		}
	}
};