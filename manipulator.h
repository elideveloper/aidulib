#ifndef MANIPULATOR_H
#define MANIPULATOR_H

#include "link.h"
#include "utility.h"

class Manipulator {
public:
	Manipulator(Link* links, byte numLinks);
	Point computePosition();
private:
	byte _numLinks;
	Link* _links;
};

#endif