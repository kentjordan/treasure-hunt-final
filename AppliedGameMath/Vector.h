#pragma once

#include "Point.h"

class Vector {

private:
	Point* A, * B;

public:
	Vector();
	Vector(Point* A, Point* B);

	void setPlayerPoint(Point* player);
	void setGoalPoint(Point* goal);

	double distance();

};
