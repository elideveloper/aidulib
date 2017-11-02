#include "joint.h"

#include <cmath>

Joint::Joint()
{
}

Joint::Joint(Range angleRange, double angle = 0.0) : _angleRange(angleRange), angle(angle)
{
}

RotationJoint::RotationJoint() : Joint()
{
}

RotationJoint::RotationJoint(Range angleRange, double angle = 0.0) : Joint(angleRange, angle)
{
}

Point RotationJoint::computeRelativeB(double sumPrevAngles, int length)
{
	return Point(0.0, cos(this->_angle + sumPrevAngles) * length, sin(this->_angle + sumPrevAngles) * length);
}

TwistingJoint::TwistingJoint() : Joint()
{
}

TwistingJoint::TwistingJoint(Range angleRange, double angle = 0.0) : Joint(angleRange, angle)
{
}

Point TwistingJoint::computeRelativeB(double sumPrevAngles, int length)
{
	return Point(sin(this->_angle + sumPrevAngles) * length, cos(this->_angle + sumPrevAngles) * length, 0.0);
}

RevolutionJoint::RevolutionJoint() : Joint()
{
}

RevolutionJoint::RevolutionJoint(Range angleRange, double angle = 0.0) : Joint(angleRange, angle)
{
}

Point RevolutionJoint::computeRelativeB(double sumPrevAngles, int length)
{
	// TODO
}