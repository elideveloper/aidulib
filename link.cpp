#include "link.h"

#include <cmath>

Point Link::computeB(const Link & prevLink)
{
	double projectionYZ = cos(this->_joint.rotationAngle) * this->_length;
	double z = sin(this->_joint.twistAngle) * projectionYZ;
	double y = cos(this->_joint.twistAngle) * projectionYZ;
	double x = sqrt(this->_length * this->_length - projectionYZ * projectionYZ);
	return Point(this->_a.x + x, this->_a.y + y, this->_a.z + z);
}
