#pragma once
#include "Triangle.h"
#include <list>

class Tor
{
private:
	std::list <Triangle> triangles;

	int id;
	static int next_id;

	static int next_user_id()
	{
		next_id++;
		return next_id;
	}
public:

	double Radius_of_rotation, radius_of_circle;
	Point center;

	Tor(double x, double y, double z, double R, double r);

	Tor(Point *center, double R, double r);

	Tor(const Point &center, double R, double r);
};
int Tor::next_id = 0;