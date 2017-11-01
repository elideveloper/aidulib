#ifndef JOINT_H
#define JOINT_H

#include "range.h"

class Joint {
public:
	double twistAngle;
	double rotationAngle;

private:

	Range _twistRange;
	Range _rotationRange;
};

#endif
