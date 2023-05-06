#include <cmath>
#include <iostream>
#include <limits>

class Triangle {
private:
    double a;
    double b;
    double c;
public:
    Triangle(double a, double b, double c) {
        this->a = a;
        this->b = b;
        this->c = c;
    }

    double getArea() const {
        double p = (a + b + c) / 2;
        double S = sqrt(p * (p - a) * (p - b) * (p - c));
        return S;
    };

    void print() const {
        std::cout << "Triangle: " << a << ", " << b << ", " << c << std::endl;
        std::cout << "Area: " << getArea() << std::endl;
    };

    ~Triangle() {
        
    }
};

class TriangleFactory {
public:
    static Triangle *getTriangleFromConsole() {
        double a, b, c;

        while (true) {
            a = getSide(1);
            b = getSide(2);
            c = getSide(3);

            bool triangleExists = a + b > c && a + c > b && b + c > a;
            if (!triangleExists) {
                std::cout << "Треугольник не существует" << std::endl;
                continue;
            }

            break;
        }

        return new Triangle(a, b, c);
    }

private:
    static double getSide(int sideNumber) {
        double a;
        while (true) {
            std::cout << "Введите " << sideNumber << " сторону треугольника: ";
            std::cin >> a;
            if (std::cin.fail()) {
                std::cout << "Некорректный ввод " << sideNumber << " стороны" << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }

            break;
        }

        return a;
    }
};

int main() {
    Triangle *triangle = TriangleFactory::getTriangleFromConsole();
    triangle->print();
    delete triangle;

    return 0;
}