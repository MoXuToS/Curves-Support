#pragma once
#include<vector>
#include<iostream>

// Для реализации вектора
using namespace std;

class Shape
{
public:
	/*
	Для создания объекта нужен массив точек,
	для его создания можно использовать двухмерный вектор,
	который мы будем заполнять координатами x, y, z при определенном значение 
	t принадлежащему отрезку от 0 до 2 pi
	Например 
	vector<vector<double>> Coordinates
	Coordinates[i].push_back(x(t))
	Coordinates[i].push_back(y(t))
	Coordinates[i].push_back(z(t))
	*/
	double x, y, z;
	double a, b, c;
	double r;
	string Type;
	void Print_Coord();
	void Print_Coord(double t);
	void derivative(double t, vector<double>& vec);
	Shape()
	{
		this->x = 0;
		this->y = 0;
		this->z = 0;
		this->a = 0;
		this->b = 0;
		this->c = 0;
		this->r = 0;
		this->Type = "";
	}
};

class Circle : public Shape
{
public:
	Circle(double R) : Shape()
	{
		// Так как в случаной генерации все радиусы положительны
		// Дополнительная проверка на их положительность не трубется
		this->r = R;
		this->x = R * cos(0);
		this->y = R * sin(0);
		this->z = 0;
		this->Type = "Circle";
	}
	// Оператор сравнения по радиусам
	bool operator<(const Circle& other) const 
	{
		return r < other.r;
	}
};

class Ellipse : public Shape
{
public:
	Ellipse(double a, double b) : Shape()
	{
		this->a = a;
		this->b = b;
		this->x = a * cos(0);
		this->y = b * sin(0);
		this->z = 0;
		this->Type = "Ellipse";
	}
};

class Curve : public Shape
{
public:
	Curve(double a, double b, double c) : Shape()
	{
		this->a = a;
		this->b = b;
		this->c = c;
		this->x = a * cos(0);
		this->y = b * sin(0);
		this->z = c * 0;
		this->Type = "3D Curve";
	}
};
