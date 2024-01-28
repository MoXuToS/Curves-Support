#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Curve3D 
{
public:
    virtual ~Curve3D() {}
    virtual vector<double> getPoint(double t) const = 0;
    virtual vector<double> getDerivative(double t) const = 0;
};

class Circle : Curve3D
{
public:
    Circle(double radius) : radius(radius) {}
    vector<double> getPoint(double t) const override;
    vector<double> getDerivative(double t) const override;
private:
    double radius;
};

class Ellipse : Curve3D
{
public:
    Ellipse(double radiusX,double radiusY) : radiusX(radiusX), radiusY(radiusY) {}
    vector<double> getPoint(double t) const override;
    vector<double> getDerivative(double t) const override;
private:
    double radiusX;
    double radiusY;
};

class Helix : Curve3D
{
public:
    Helix(double radius,double step) : radius(radius), step(step) {}
    vector<double> getPoint(double t) const override;
    vector<double> getDerivative(double t) const override;
private:
    double radius;
    double step;
};