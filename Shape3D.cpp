#include <Shape3D.h>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<double> Circle::getPoint(double t) const
{
    double x = radius * cos(t);
    double y = radius * sin(t);
    double z = 0;
    return {x,y,z};
};
vector<double> Circle::getDerivative(double t) const 
{
        
};

vector<double> Ellipse::getPoint(double t) const
{

};
vector<double> Ellipse::getDerivative(double t) const
{

}; 

vector<double> Helix::getPoint(double t) const 
{

};
vector<double> Helix::getDerivative(double t) const
{

};