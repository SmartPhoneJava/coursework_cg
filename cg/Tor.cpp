#include "stdafx.h"
#include "Tor.h"
#include "Point.h"


Tor::Tor(double x, double y, double z, double R, double r)
{
	this->id = Tor::next_id++;
	this->center = new Point(x,y,z);
	this->Radius_of_rotation = R;
	this->radius_of_circle = r;
}

Tor::Tor(Point *center, double R, double r)
{
	this->id = Tor::next_id++;
	this->center = center;
	this->Radius_of_rotation = R;
	this->radius_of_circle = r;
}

Tor::Tor(const Point &center, double R, double r)
{
	this->id = Tor::next_id++;
	this->center = center;
	this->Radius_of_rotation = R;
	this->radius_of_circle = r;
}