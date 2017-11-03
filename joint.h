#ifndef JOINT_H
#define JOINT_H

#include "range.h"
#include "angles.h"
#include "point.h"

class Joint {
public:
	Joint();
	Joint(Range _twistRange, double angle = 0.0);
	virtual void changeAngles(Angles & angles) = 0; // computeResultingPoint
	double getAngle() const;
protected:
	Range _angleRange;
	double _angle;
};

// rotation in vertical plane
class RotationJoint : public Joint {
public:
	RotationJoint();
	RotationJoint(Range _twistRange, double angle = 0.0);
	virtual void changeAngles(Angles & angles);
};

// twisting in horizontal plane
class TwistingJoint : public Joint {
public:
	TwistingJoint();
	TwistingJoint(Range _twistRange, double angle = 0.0);
	virtual void changeAngles(Angles & angles);
};

// revolution around its axis
class RevolutionJoint : public Joint {
public:
	RevolutionJoint();
	RevolutionJoint(Range _twistRange, double angle = 0.0);
	virtual void changeAngles(Angles & angles);
};

#endif
