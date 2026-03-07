// Copyright 2025 UNN-CS Team

#include <gtest/gtest.h>
#include "circle.h"
#include "tasks.h"

TEST(CircleTest, InitializationWithRadius) {
    Circle c(5);
    EXPECT_NEAR(c.getRadius(), 5, 0.001);
    EXPECT_NEAR(c.getFerence(), 31.4159, 0.001);
    EXPECT_NEAR(c.getArea(), 78.5398, 0.001);
}

TEST(CircleTest, SetRadius) {
    Circle c(5);
    c.setRadius(10);
    EXPECT_NEAR(c.getRadius(), 10, 0.001);
    EXPECT_NEAR(c.getFerence(), 62.8318, 0.001);
    EXPECT_NEAR(c.getArea(), 314.159, 0.001);
}

TEST(CircleTest, SetFerence) {
    Circle c(5);
    c.setFerence(31.4159);
    EXPECT_NEAR(c.getRadius(), 5, 0.001);
    EXPECT_NEAR(c.getArea(), 78.5398, 0.001);
}

TEST(CircleTest, SetArea) {
    Circle c(5);
    c.setArea(78.5398);
    EXPECT_NEAR(c.getRadius(), 5, 0.001);
    EXPECT_NEAR(c.getFerence(), 31.4159, 0.001);
}

TEST(CircleTest, ZeroRadius) {
    Circle c(0);
    EXPECT_NEAR(c.getRadius(), 0, 0.001);
    EXPECT_NEAR(c.getFerence(), 0, 0.001);
    EXPECT_NEAR(c.getArea(), 0, 0.001);
}

TEST(CircleTest, NegativeRadius) {
    Circle c(-5);
    EXPECT_NEAR(c.getRadius(), 0, 0.001);
    EXPECT_NEAR(c.getFerence(), 0, 0.001);
    EXPECT_NEAR(c.getArea(), 0, 0.001);
}

TEST(CircleTest, LargeRadius) {
    Circle c(1000000);
    EXPECT_NEAR(c.getRadius(), 1000000, 0.001);
    EXPECT_NEAR(c.getFerence(), 6283185.307, 0.001);
    EXPECT_NEAR(c.getArea(), 3141592653589.793, 0.001);
}

TEST(CircleTest, SetNegativeFerence) {
    Circle c(5);
    c.setFerence(-10);
    EXPECT_NEAR(c.getRadius(), 0, 0.001);
    EXPECT_NEAR(c.getArea(), 0, 0.001);
}

TEST(CircleTest, SetNegativeArea) {
    Circle c(5);
    c.setArea(-10);
    EXPECT_NEAR(c.getRadius(), 0, 0.001);
    EXPECT_NEAR(c.getFerence(), 0, 0.001);
}

TEST(CircleTest, SetZeroFerence) {
    Circle c(5);
    c.setFerence(0);
    EXPECT_NEAR(c.getRadius(), 0, 0.001);
    EXPECT_NEAR(c.getArea(), 0, 0.001);
}

TEST(CircleTest, SetZeroArea) {
    Circle c(5);
    c.setArea(0);
    EXPECT_NEAR(c.getRadius(), 0, 0.001);
    EXPECT_NEAR(c.getFerence(), 0, 0.001);
}

TEST(TasksTest, CalculateGap) {
    double gap = calculateGap();
    EXPECT_NEAR(gap, 0.159, 0.001);
}

TEST(TasksTest, CalculateGapWithZeroRadius) {
    Circle c(0);
    c.setFerence(1);
    EXPECT_NEAR(c.getRadius(), 0.159, 0.001);
}

TEST(TasksTest, CalculateGapWithLargeRadius) {
    Circle c(6378100);
    double ropeLength = c.getFerence() + 1;
    Circle newCircle(0);
    newCircle.setFerence(ropeLength);
    EXPECT_NEAR(newCircle.getRadius() - 6378100, 0.159, 0.001);
}

TEST(TasksTest, CalculatePoolCost) {
    double cost = calculatePoolCost();
    EXPECT_NEAR(cost, 72256.6310, 0.001);
}

TEST(TasksTest, CalculatePoolCostWithZeroRadius) {
    Circle pool(0);
    Circle poolWithPath(1);
    double concreteArea = poolWithPath.getArea() - pool.getArea();
    double fenceLength = poolWithPath.getFerence();
    EXPECT_NEAR(concreteArea, 3.14159, 0.001);
    EXPECT_NEAR(fenceLength, 6.28318, 0.001);
}

TEST(TasksTest, CalculatePoolCostWithLargeRadius) {
    Circle pool(1000);
    Circle poolWithPath(1001);
    double concreteArea = poolWithPath.getArea() - pool.getArea();
    double fenceLength = poolWithPath.getFerence();
    EXPECT_NEAR(concreteArea, 6286.3268998, 0.001);
    EXPECT_NEAR(fenceLength, 6289.4684924, 0.001);
}

TEST(TasksTest, CalculatePoolCostWithNegativeRadius) {
    Circle pool(-3);
    Circle poolWithPath(1);
    double concreteArea = poolWithPath.getArea() - pool.getArea();
    double fenceLength = poolWithPath.getFerence();
    EXPECT_NEAR(concreteArea, 3.14159, 0.001);
    EXPECT_NEAR(fenceLength, 6.28318, 0.001);
}

TEST(TasksTest, CalculatePoolCostWithZeroPathWidth) {
    Circle pool(3);
    Circle poolWithPath(3);
    double concreteArea = poolWithPath.getArea() - pool.getArea();
    double fenceLength = poolWithPath.getFerence();
    EXPECT_NEAR(concreteArea, 0, 0.001);
    EXPECT_NEAR(fenceLength, 18.8495, 0.001);
}

TEST(CircleTest, SetZeroFerence1) {
    Circle c(105);
    c.setRadius(501);
    EXPECT_NEAR(c.getRadius(), 501, 0.001);
}
