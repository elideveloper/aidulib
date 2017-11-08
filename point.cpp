#include "point.h"

#include <math.h>

Point::Point() : x(0), y(0), z(0)
{
}

Point::Point(int x, int y, int z) : x(x), y(y), z(z)
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

int Point::distanceTo(int x, int y, int z) const
{
	return sqrt((long)(x - this->x)*(x - this->x) + (long)(y - this->y)*(y - this->y) + (long)(z - this->z)*(z - this->z));
}

int Point::distanceTo(const Point & point) const
{
	return sqrt((long)(point.x - this->x)*(point.x - this->x) + (long)(point.y - this->y)*(point.y - this->y) + (long)(point.z - this->z)*(point.z - this->z));
}
