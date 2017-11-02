#include "joint.h"

Joint::Joint()
{
}

Joint::Joint(Range twistRange, Range rotationRange, double twistAngle, double rotationAngle)
	: _twistRange(twistRange), _rotationRange(rotationRange), twistAngle(twistAngle), rotationAngle(rotationAngle)
{
}
