#ifndef JOINT_H
#define JOINT_H

#include "range.h"

class Joint {
public:
	Joint();
	Joint(Range _twistRange, Range _rotationRange, double twistAngle = 0.0, double rotationAngle = 0.0);
	double twistAngle;
	double rotationAngle;
private:
	Range _twistRange;
	Range _rotationRange;
};

#endif
