// Copyright 2022 UNN-CS
#ifndef INCLUDE_CIRCLE_H_
#define INCLUDE_CIRCLE_H_
#include <cstdint>

class Circle {
private:
  double radius = 0.0;
  double ference = 0.0;
  double area = 0.0;

public:
  explicit Circle(double rad);
  void setRadius(double rad);
  void setFerence(double fer);
  void setArea(double ar);
  double getRadius();
  double getFerence();
  double getArea();
};

#endif  // INCLUDE_CIRCLE_H_