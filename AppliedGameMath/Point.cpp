#include "Point.h"

Point::Point() : x{ 1 }, y{ 1 } {}

Point::Point(int x = 1, int y = 1): x(x), y(y) {}

void Point::setX(int x) {
	this->x = x;
}

void Point::setY(int y) {
	this->y = y;
}

int Point::getX() {
	return this->x;
}

int Point::getY() {
	return this->y;
}