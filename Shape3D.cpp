#include <Shape3D.h>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<double> Circle::getPoint(double t) const
{
    double x = radius * cos(t);
    double y = radius * sin(t);
    double z = 0.0;
    return {x,y,z};
};
vector<double> Circle::getDerivative(double t) const 
{
    double dx = -radius * sin(t);
    double dy = radius * cos(t);
    double dz = 0.0;
    return {dx,dy,dz};
};

double Circle::getRadius()
{
    return this->radius;
}

vector<double> Ellipse::getPoint(double t) const
{
    double x = radiusX * sin(t);
    double y = radiusY * cos(t);
    double z = 0.0;
    return {x,y,z};
};

vector<double> Ellipse::getDerivative(double t) const
{
    double dx = -radiusX * cos(t);
    double dy = radiusY * sin(t);
    double dz = 0.0;
    return {dx,dy,dz};
}; 

vector<double> Helix::getPoint(double t) const 
{
    double x = radius * cos(t);
    double y = radius * sin(t);
    double z = step * t / (2*M_PI_4);
    return {x,y,z};
};

vector<double> Helix::getDerivative(double t) const
{
    double dx = -radius * sin(t);
    double dy = radius * cos(t);
    double dz = step / (2*M_PI);
    return {dx,dy,dz};
};