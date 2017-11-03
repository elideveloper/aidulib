#include "joint.h"

#include <cmath>

Joint::Joint()
{
}

Joint::Joint(Range angleRange, double angle) : _angleRange(angleRange), _angle(angle)
{
}

double Joint::getAngle() const
{
	return this->_angle;
}

RotationJoint::RotationJoint() : Joint()
{
}

RotationJoint::RotationJoint(Range angleRange, double angle) : Joint(angleRange, angle)
{
}

void RotationJoint::changeAngles(Angles & angles)
{
	angles.rotationAngle += this->_angle;
}

TwistingJoint::TwistingJoint() : Joint()
{
}

TwistingJoint::TwistingJoint(Range angleRange, double angle) : Joint(angleRange, angle)
{
}

void TwistingJoint::changeAngles(Angles & angles)
{
	angles.twistingAngle += this->_angle;
}

RevolutionJoint::RevolutionJoint() : Joint()
{
}

RevolutionJoint::RevolutionJoint(Range angleRange, double angle) : Joint(angleRange, angle)
{
}

void RevolutionJoint::changeAngles(Angles & angles)
{
	angles.revolutionAngle += this->_angle;
}