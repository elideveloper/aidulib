#include "utility.h"

double radianToDegree(double angle) {
	return angle * 180.0 / PI;
}

double degreeToRadian(double angle) {
	return angle / 180.0 * PI;
}