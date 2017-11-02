#ifndef JOINT_H
#define JOINT_H

#include "range.h"
#include "point.h"

// types of joints: rotation, revolution, twisting

class Joint {
public:
	Joint();
	Joint(Range _twistRange, double angle = 0.0);
	virtual Point computeRelativeB(double sumPrevAngles, int length) = 0;
protected:
	Range _angleRange;
	double _angle;
};

// rotation in vertical plane
class RotationJoint : public Joint {
public:
	RotationJoint();
	RotationJoint(Range _twistRange, double angle = 0.0);
	virtual Point computeRelativeB(double sumPrevAngles, int length);
};

// twisting in horizontal plane
class TwistingJoint : public Joint {
public:
	TwistingJoint();
	TwistingJoint(Range _twistRange, double angle = 0.0);
	virtual Point computeRelativeB(double sumPrevAngles, int length);
};

// revolution around its axis
class RevolutionJoint : public Joint {
public:
	RevolutionJoint();
	RevolutionJoint(Range _twistRange, double angle = 0.0);
	virtual Point computeRelativeB(double sumPrevAngles, int length);
};

#endif
