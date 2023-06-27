//=============================================================
#include <iostream>
#include <ctime>
#include <cstdlib>
#include<vector>
#include <algorithm>
#include <thread>
#include "Shape.h"
//=============================================================

using namespace std;
double const pi = 3.14159;
//=============================================================

void Generate_Element(vector<Shape>& a);
void sumHalf(const vector<Circle>& vec, int start, int end, double& result);

//=============================================================

int main() {
	setlocale(LC_ALL, "Russian");
	srand(time(NULL)); // инициализация генерации случайных чисел
	vector<Shape> Shapes; // вектор элементов типа кривая
	// Создаем массив элементов типа Shape
	for (int i = 0; i < 1000; i++) 
		Generate_Element(Shapes);
	for (int i = 0; i < Shapes.size(); i++)
	{
		vector<double> derivatives;
		cout << "вектор номер " << i + 1 << endl;
		cout << "координаты\n";
		Shapes[i].Print_Coord(pi / 4);
		// Высчитываем точку
		Shapes[i].derivative(pi / 4, derivatives);
		cout << "производная в точке\n";
		cout << "{ " << derivatives[0] << " ; " << derivatives[1] << " ; " << derivatives[2] << " }\n\n";
	}
	vector<Circle> Circles;
	for (auto i : Shapes)
		if (i.Type == "Circle")
			Circles.push_back(Circle(i.r));
	sort(Circles.begin(), Circles.end());
	double sum = 0;
	// Создаем два потока и передаем каждому половину контрейнера для подсчета суммы
	thread t1(sumHalf, ref(Circles), 0, Circles.size() / 2, ref(sum));
	thread t2(sumHalf, ref(Circles), Circles.size() / 2, Circles.size(), ref(sum));
	// Ждем завершения работы потоков
	t1.join();
	t2.join();
	cout << "Сумма радиусов кругов равна " << sum << endl;
	sum = 0;
	for (auto i : Circles)
		sum += i.r;
	cout << "Сумма радиусов кругов равна " << sum << endl;
}

//=============================================================
// Создаем элемент массива случайного типа
void Generate_Element(vector<Shape>& vec)
{
	int path = 1 + rand() % 3;
	double R, a, b, c;
	switch (path)
	{
	case 1:
		R = 0.1 + rand() % 100 / 10.0; // Радиус не может быть равен нулю, так как это будет точка, а не круг
		vec.push_back(Circle(R));
		break;
	case 2:
		a = rand() % 100 / 10.0;
		b = rand() % 100 / 10.0;
		vec.push_back(Ellipse(a, b));
		break;
	case 3:
		a = rand() % 100 / 10.0;
		b = rand() % 100 / 10.0;
		c = rand() % 100 / 10.0;
		vec.push_back(Curve(a, b, c));
		break;
	default:
		break;
	}
}

// Функция, которая будет выполняться в отдельном потоке для подсчета суммы половины элементов вектора
void sumHalf(const vector<Circle>& vec, int start, int end, double& result) 
{
	for (int i = start; i < end; ++i)
		result += vec[i].r;
}


