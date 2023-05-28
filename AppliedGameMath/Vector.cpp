#include "Vector.h"
#include <math.h>

Vector::Vector() {

}

Vector::Vector(Point* player, Point* goal) : A(player), B(goal) {}

void Vector::setPlayerPoint(Point* player) {
	this->A = player;
}
void Vector::setGoalPoint(Point* goal) {
	this->B = goal;
}

double Vector::distance() {

	double a = this->B->getX() - this->A->getX();
	double b = this->B->getY() - this->A->getY();

	return sqrt((a * a) + (b * b));
}
