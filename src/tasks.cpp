// Copyright 2025 UNN-CS Team

#include <vector>
#include "tasks.h"
#include "circle.h"

double calculatEarthandRope() {
  Circle earth(6378.1 * 1000);
  double originalFerence = earth.getFerence();

  double newFerence = originalFerence + 1.0;
  Circle newCircle(newFerence);

  double newRadius = newCircle.getRadius();

  double gap = newRadius - (6378.1 * 1000);

  return gap;
}

std::vector<double> calculatePool() {
  double poolRadius = 3.0;
  double walkwayWidth = 1.0;

  Circle pool(poolRadius);
  Circle walkway(poolRadius + walkwayWidth);

  double walkwayArea = walkway.getArea() - pool.getArea();
  double walkwayCost = walkwayArea * 1000.0;

  double perimeter = pool.getFerence();
  double fenceCost = perimeter * 2000.0;

  double totalCost = walkwayCost + fenceCost;

  return { walkwayCost, fenceCost, totalCost };
}
