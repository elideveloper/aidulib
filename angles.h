#ifndef ANGLES_H
#define ANGLES_H

struct Angles {
	double rotationAngle;
	double twistingAngle;
	double revolutionAngle;
	Angles();
	Angles(double rotationAngle, double twistingAngle, double revolutionAngle);
	Angles(const Angles & angles);
	Angles & operator= (const Angles & angles);
};

#endif