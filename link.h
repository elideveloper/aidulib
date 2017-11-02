#ifndef LINK_H
#define LINK_H

#include "joint.h"
#include "point.h"

class Link {
public:
	Link();
	Link(int length, Joint* joint);
	Link(const Link & link);
	Link & operator=(const Link & link);
	Point computeB();
	Point computeB(const Link & prevLink);
	void setA(Point a);
private:
	Point _a;
	Point _b;
	int _length;
	Joint* _joint;
};

#endif