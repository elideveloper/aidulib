#ifndef LINK_H
#define LINK_H

#include "joint.h"
#include "point.h"

class Link {
public:
	Point computeB(const Link & prevLink);
private:
	Point _a;
	Point _b;
	int _length;
	Joint _joint;
};

#endif