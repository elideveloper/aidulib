#include "point.h"

Point::Point() : x(0.0), y(0.0), z(0.0)
{
}

Point::Point(double x, double y, double z) : x(x), y(y), z(z)
{
}

Point::Point(const Point & point)
{
	this->x = point.x;
	this->y = point.y;
	this->z = point.z;
}

Point & Point::operator=(const Point & point)
{
	if (&point == this) return *this;
	this->x = point.x;
	this->y = point.y;
	this->z = point.z;
	return *this;
}
