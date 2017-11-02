#include "link.h"

#include <cmath>
#include <iostream>
Link::Link()
{
}

Link::Link(int length, Joint joint) : _length(length), _joint(joint)
{
}

Link::Link(const Link & link)
{
	this->_a = link._a;
	this->_b = link._b;
	this->_length = link._length;
	this->_joint = link._joint;
}

Link & Link::operator=(const Link & link)
{
	if (&link == this) return *this;
	this->_a = link._a;
	this->_b = link._b;
	this->_length = link._length;
	this->_joint = link._joint;
	return *this;
}

Point Link::computeB()
{
	double projectionXY = cos(this->_joint.twistAngle) * this->_length;
	double z = sin(this->_joint.twistAngle) * this->_length;
	double y = cos(this->_joint.rotationAngle) * projectionXY;
	double x = sin(this->_joint.rotationAngle) * projectionXY;
	this->_b = Point(this->_a.x + x, this->_a.y + y, this->_a.z + z);
	printf("\nPos: x=%.2f, y=%.2f, z=%.2f", this->_b.x, this->_b.y, this->_b.z);
	return this->_b;
}

Point Link::computeB(const Link & prevLink)
{
	this->_joint.twistAngle = this->_joint.twistAngle + prevLink._joint.twistAngle;
	this->_joint.rotationAngle = this->_joint.rotationAngle + prevLink._joint.rotationAngle;
	double projectionXY = cos(this->_joint.twistAngle) * this->_length;
	double z = sin(this->_joint.twistAngle) * this->_length;
	double y = cos(this->_joint.rotationAngle) * projectionXY;
	double x = sin(this->_joint.rotationAngle) * projectionXY;
	this->_b = Point(this->_a.x + x, this->_a.y + y, this->_a.z + z);
	printf("\nPoss: x=%.2f, y=%.2f, z=%.2f", this->_b.x, this->_b.y, this->_b.z);
	return this->_b;
}

void Link::setA(Point a)
{
	this->_a = a;
}
