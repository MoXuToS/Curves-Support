#include <iostream>
#include <vector>

using namespace std;

class Curve3D 
{
public:
    virtual ~Curve3D() {}
    virtual vector<double> getPoint(double t);
};

class Circle : Curve3D
{

};

class Ellipse : Curve3D
{

};

class Helix : Curve3D
{

};