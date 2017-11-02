#ifndef POINT_H
#define POINT_H

class Point {
public:
	Point();
	Point(double x, double y, double z);
	Point(const Point & point);
	Point & operator= (const Point & point);
	double x;
	double y;
	double z;
private:
};

#endif