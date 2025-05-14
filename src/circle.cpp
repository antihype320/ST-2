// Copyright 2022 UNN-CS
#include <cstdint>
#include <cmath>
#include "circle.h"


Circle::Circle(double rad) {
	if (rad < 0) {
		throw "Radius less than 0";
	}
	radius = rad;
	ference = 2 * rad * 3.14;
	area = 3.14 * rad * rad;
}

void Circle::setRadius(double rad) {
	if (rad < 0) {
		throw "Radius less than 0";
	}
	radius = rad;
	ference = 2 * rad * 3.14;
	area = 3.14 * rad * rad;
}

void Circle::setFerence(double fer) {
	if (fer < 0) {
		throw "Ference less than 0";
	}
	ference = fer;
	radius = fer / 2 / 3.14;
	area = 3.14 * radius * radius;
}

void Circle::setArea(double ar) {
	if (ar < 0) {
		throw "Area less than 0";
	}
	area = ar;
	radius = sqrt(ar / 3.14);
	ference = radius * 2 * 3.14;
}

double Circle::getRadius() {
	return radius;
}

double Circle::getFerence() {
	return ference;
}

double Circle::getArea() {
	return area;
}
