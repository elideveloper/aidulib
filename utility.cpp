#include "utility.h"

int radianToDegree(double angle) {
	return angle * 180 / PI;
}

double degreeToRadian(int angle) {
	return angle / 180.0 * PI;
}
/*
int random(int max) {
	return rand() % max;
}

int random(int min, int max) {
	return (rand() % (max - min)) + min;
}*/