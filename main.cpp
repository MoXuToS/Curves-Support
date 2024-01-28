#include <algorithm>
#include <cmath>
#include <iostream>
#include <Shape3D.h>
#include <vector>

int main()
{
    using namespace std;
    // Создание контейнера случайных объектов
    vector<Curve3D*> curves;

    // Добавление случайных объектов кривых в контейнер
    curves.push_back(new Circle(5.0));
    curves.push_back(new Ellipse(3.0, 4.0));
    curves.push_back(new Helix(2.0, 1.0));

    double t = M_PI / 4;
    for(const auto& curve: curves)
    {
        vector<double> point = curve->getPoint(t);
        vector<double> derivative = curve->getDerivative(t);
        cout << "Point:(" << point[0] << "," << point[1] << "," << point[2] << ")" << endl;
        cout << "Derivative:(" << derivative[0] << "," << derivative[1] << derivative[2] << ")" << endl; 
    }

    // Создание контейнера только с кругами
    vector<Circle*> circles;
    for(const auto& curve : curves)
        if (dynamic_cast<Circle*>(curve))
            circles.push_back(static_cast<Circle*>(curve));

    // Сортировка только кругами
    sort(circles.begin(),circles.end(), [](Circle* a, Circle* b)
    {
        return a.radius < b.radius;
    });

    // Вычисление общий суммы радиусов всех кргуов
    double TotalSum = 0.0;
    for(const auto& circle : circles)
        TotalSum += circle.radius;

    cout << "Total sum of radius: " << TotalSum << endl;

    // Очистка памяти
    for(const auto& curve : curves) 
        delete curve;    
    return 0;
}