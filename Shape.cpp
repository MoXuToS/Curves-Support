#include "Shape.h"
#include<iostream>
#include<vector>

void Shape::Print_Coord()
{
	double t = 0;
	if (Type == "Circle")
	{
		x = r * cos(t);
		y = r * sin(t);
		z = 0;
		cout << "{ " << x << " ; " << y << " ; " << z << " }\n";
	}
	else if (Type == "Ellipse")
	{
		x = a * cos(t);
		y = b * sin(t);
		z = 0;
		cout << "{ " << x << " ; " << y << " ; " << z << " }\n";
	}
	else
	{
		x = a * cos(t);
		y = b * sin(t);
		z = c * t;
		cout << "{ " << x << " ; " << y << " ; " << z << " }\n";
	}
}

void Shape::Print_Coord(double t)
{
	if (Type == "Circle")
	{
		x = r * cos(t);
		y = r * sin(t);
		z = 0;
		cout << "{ " << x << " ; " << y << " ; " << z << " }\n";
	}
	else if (Type == "Ellipse")
	{
		x = a * cos(t);
		y = b * sin(t);
		z = 0;
		cout << "{ " << x << " ; " << y << " ; " << z << " }\n";
	}
	else
	{
		x = a * cos(t);
		y = b * sin(t);
		z = c * t;
		cout << "{ " << x << " ; " << y << " ; " << z << " }\n";
	}
}

void Shape::derivative(double t, vector<double>& vec)
{
	double dx, dy, dz;
	if (Type == "Circle")
	{
		dx = -r * sin(t);
		dy = r * cos(t);
		dz = 0;
		vec.push_back(dx);
		vec.push_back(dy);
		vec.push_back(dz);
	}
	else if (Type == "Ellipse")
	{
		dx = -a * sin(t);
		dy = b * cos(t);
		dz = 0;
		vec.push_back(dx);
		vec.push_back(dy);
		vec.push_back(dz);
	}
	else
	{
		dx = b * cos(t) - (a + b * t) * sin(t);
		dy = b * sin(t) + (a + b * t) * cos(t);
		dz = c;
		vec.push_back(dx);
		vec.push_back(dy);
		vec.push_back(dz);
	}
}
