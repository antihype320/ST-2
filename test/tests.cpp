// Copyright 2025 UNN-CS Team
#include <gtest/gtest.h>
#include <cmath>
#include <cstdint>
#include <vector>
#include "circle.h"
#include "tasks.h"

TEST(test_circle, radius_is_zero) {
  Circle c(0.0);
  EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
  EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
  EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
}

TEST(test_circle, radius_is_five) {
  Circle c(5.0);
  EXPECT_DOUBLE_EQ(c.getRadius(), 5.0);
  EXPECT_DOUBLE_EQ(c.getFerence(), 2 * 5.0 * M_PI);
  EXPECT_DOUBLE_EQ(c.getArea(), M_PI * 5.0 * 5.0);
}

TEST(test_circle, radius_is_double) {
  Circle c(123.456);
  EXPECT_DOUBLE_EQ(c.getRadius(), 123.456);
  EXPECT_DOUBLE_EQ(c.getFerence(), 2 * 123.456 * M_PI);
  EXPECT_DOUBLE_EQ(c.getArea(), M_PI * 123.456 * 123.456);
}

TEST(test_circle, radius_is_less_zero) {
  EXPECT_ANY_THROW(Circle c(-10.0));
}

TEST(test_circle, check_set_rad) {
  Circle c(0.0);
  c.setRadius(23.46);
  EXPECT_DOUBLE_EQ(c.getRadius(), 23.46);
  EXPECT_DOUBLE_EQ(c.getFerence(), 2 * 23.46 * M_PI);
  EXPECT_DOUBLE_EQ(c.getArea(), M_PI * 23.46 * 23.46);
}

TEST(test_circle, check_set_rad_less_zero) {
  Circle c(0.0);
  EXPECT_ANY_THROW(c.setRadius(-345.89));
}

TEST(test_circle, check_set_ference_zero) {
  Circle c(23.4);
  c.setFerence(0.0);
  EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
  EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
  EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
}

TEST(test_circle, check_set_ference) {
  Circle c(234.0);
  c.setFerence(456.98);
  EXPECT_DOUBLE_EQ(c.getFerence(), 456.98);
  EXPECT_DOUBLE_EQ(c.getRadius(), 456.98 / (2 * M_PI));
  EXPECT_DOUBLE_EQ(c.getArea(), M_PI * c.getRadius() * c.getRadius());
}

TEST(test_circle, check_set_ference_less_zero) {
  Circle c(0.0);
  EXPECT_ANY_THROW(c.setFerence(-234.9));
}

TEST(test_circle, check_set_area_zero) {
  Circle c(23.0);
  c.setArea(0.0);
  EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
  EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
  EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
}

TEST(test_circle, check_set_area) {
  Circle c(24.34);
  c.setArea(3455.6);
  EXPECT_DOUBLE_EQ(c.getArea(), 3455.6);
  EXPECT_DOUBLE_EQ(c.getRadius(), sqrt(3455.6 / M_PI));
  EXPECT_DOUBLE_EQ(c.getFerence(), c.getRadius() * 2 * M_PI);
}

TEST(test_circle, check_set_area_less_zero) {
  Circle c(0.0);
  EXPECT_ANY_THROW(c.setArea(-22.9));
}

TEST(test_circle, area_of_unity_radius) {
  Circle c(1.0);
  EXPECT_DOUBLE_EQ(c.getRadius(), 1.0);
  EXPECT_DOUBLE_EQ(c.getFerence(), 2 * M_PI);
  EXPECT_DOUBLE_EQ(c.getArea(), M_PI);
}

TEST(test_circle, area_with_fractional_radius) {
  Circle c(2.5);
  EXPECT_DOUBLE_EQ(c.getRadius(), 2.5);
  EXPECT_DOUBLE_EQ(c.getFerence(), 2 * 2.5 * M_PI);
  EXPECT_DOUBLE_EQ(c.getArea(), M_PI * 2.5 * 2.5);
}

TEST(test_circle, check_radius_after_area_set) {
  Circle c(10.0);
  c.setArea(314.159265);
  EXPECT_NEAR(c.getRadius(), 10.0, 1e-9);
  EXPECT_NEAR(c.getFerence(), 62.831853, 1e-6);
}

TEST(test_circle, check_set_radius_to_zero) {
  Circle c(10.0);
  c.setRadius(0.0);
  EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
  EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
  EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
}

TEST(test_circle, check_setting_radius_after_fency_set_zero) {
  Circle c(7.0);
  c.setFerence(0.0);
  EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
}

TEST(test_circle, check_set_area_to_large_value) {
  Circle c(5.0);
  c.setArea(10000.0);
  EXPECT_DOUBLE_EQ(c.getRadius(), sqrt(10000.0 / M_PI));
  EXPECT_DOUBLE_EQ(c.getFerence(), c.getRadius() * 2 * M_PI);
}

TEST(test_tasks, check_calculate_earth_rope) {
  double result = calculatEarthandRope();
  EXPECT_NEAR(result, 1.0 / (2 * M_PI), 1e-9);
}

TEST(test_tasks, check_calculate_pool) {
  std::vector<double> costs = calculatePool();
  EXPECT_NEAR(costs[0], 21991.148575, 1e-6);
  EXPECT_NEAR(costs[1], 37699.111843, 1e-6);
  EXPECT_NEAR(costs[2], 59690.260418, 1e-6);
}
