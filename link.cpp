#include "link.h"

#include<iostream>

Link::Link()
{
}

Link::Link(int length, Joint* joint, Angles angles) : _length(length), _joint(joint), _currAngles(angles)
{
}

Link::Link(const Link & link)
{
	this->_a = link._a;
	this->_b = link._b;
	this->_length = link._length;
	this->_joint = link._joint;
	this->_currAngles = link._currAngles;
}

Link & Link::operator=(const Link & link)
{
	if (&link == this) return *this;
	this->_a = link._a;
	this->_b = link._b;
	this->_length = link._length;
	this->_joint = link._joint;
	this->_currAngles = link._currAngles;
	return *this;
}

Point Link::computeB()
{
	this->_joint->changeAngles(this->_currAngles);
	// compute B point, revolute angle does not influence position, but infleunce to the next link
	this->_b.x = this->_a.x + cos(this->_currAngles.rotationAngle) * this->_length * sin(this->_currAngles.twistingAngle);
	this->_b.y = this->_a.y + cos(this->_currAngles.rotationAngle) * this->_length * cos(this->_currAngles.twistingAngle);
	this->_b.z = this->_a.z + sin(this->_currAngles.rotationAngle) * this->_length;
	printf("\nPos: x=%.2f, y=%.2f, z=%.2f", this->_b.x, this->_b.y, this->_b.z);
	return this->_b;
}

Point Link::computeB(const Link & prevLink)
{
	// учесть твист предыдущих линков
	this->_joint->changeAngles(this->_currAngles);
	this->_b.x = this->_a.x + cos(this->_currAngles.rotationAngle) * this->_length * sin(this->_currAngles.twistingAngle);
	this->_b.y = this->_a.y + cos(this->_currAngles.rotationAngle) * this->_length * cos(this->_currAngles.twistingAngle);
	this->_b.z = this->_a.z + sin(this->_currAngles.rotationAngle) * this->_length;
	printf("\nPos: x=%.2f, y=%.2f, z=%.2f", this->_b.x, this->_b.y, this->_b.z);
	return this->_b;
}

void Link::setA(Point a)
{
	this->_a = a;
}

void Link::setAngles(Angles angles)
{
	this->_currAngles = angles;
}

Angles Link::getAngles() const
{
	return this->_currAngles;
}

