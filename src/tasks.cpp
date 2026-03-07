// Copyright 2022 UNN-CS

#include <cmath>
#include "circle.h"
#include "tasks.h"

double calculateGap() {
    double earthRadius = 6378100;
    Circle earth(earthRadius);
    double ropeLength = earth.getFerence() + 1;
    Circle newCircle(0);
    newCircle.setFerence(ropeLength);
    return newCircle.getRadius() - earthRadius;
}

double calculatePoolCost() {
    double poolRadius = 3;
    double pathWidth = 1;
    double concreteCostPerSqm = 1000;
    double fenceCostPerMeter = 2000;

    Circle pool(poolRadius);
    Circle poolWithPath(poolRadius + pathWidth);

    double concreteArea = poolWithPath.getArea() - pool.getArea();
    double fenceLength = poolWithPath.getFerence();

    double totalConcreteCost = concreteArea * concreteCostPerSqm;
    double totalFenceCost = fenceLength * fenceCostPerMeter;

    return totalConcreteCost + totalFenceCost;
}
