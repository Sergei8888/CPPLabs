#include <iostream>
#include <utility>
#include <vector>


class Figure {
    virtual float area() = 0;

    virtual void printFigureInfo() = 0;

protected:
    std::string color;
};

class RightAngleTriangle : Figure {
private:
    float a[2];
    float b[2];
    float c[2];

public:
    RightAngleTriangle(std::string color, std::vector<float> a_coords, std::vector<float> b_coords,
                       std::vector<float> c_coords) {
        this->color = std::move(color);
        this->a[0] = a_coords[0];
        this->a[1] = a_coords[1];
        this->b[0] = b_coords[0];
        this->b[1] = b_coords[1];
        this->c[0] = c_coords[0];
        this->c[1] = c_coords[1];
    }

    float area() override {
        float ab = sqrt(pow(a[0] - b[0], 2) + pow(a[1] - b[1], 2));
        float bc = sqrt(pow(b[0] - c[0], 2) + pow(b[1] - c[1], 2));
        float ac = sqrt(pow(a[0] - c[0], 2) + pow(a[1] - c[1], 2));

        return (ab + bc + ac) / std::max(ab, std::max(bc, ac));
    }

    void printFigureInfo() override {
        std::cout << "Right angle triangle" << std::endl;
        std::cout << "Color: " << color << std::endl;
        std::cout << "A: " << a[0] << " " << a[1] << std::endl;
        std::cout << "B: " << b[0] << " " << b[1] << std::endl;
        std::cout << "C: " << c[0] << " " << c[1] << std::endl;
        std::cout << "Area: " << area() << std::endl;
    };
};

class Circle : Figure {
private:
    std::vector<float> o_coords;
    std::vector<float> a_coords;

public:
    Circle(std::string color, std::vector<float> o_coords, std::vector<float> a_coords) {
        this->color = std::move(color);
        this->o_coords = std::move(o_coords);
        this->a_coords = std::move(a_coords);
    }

    float area() override {
        float r = sqrt(pow(o_coords[0] - a_coords[0], 2) + pow(o_coords[1] - a_coords[1], 2));
        return M_PI * r * r;
    }

    void printFigureInfo() override {
        std::cout << "Circle" << std::endl;
        std::cout << "Color: " << color << std::endl;
        std::cout << "O: " << o_coords[0] << " " << o_coords[1] << std::endl;
        std::cout << "A: " << a_coords[0] << " " << a_coords[1] << std::endl;
        std::cout << "Area: " << area() << std::endl;
    };
};

int main() {
    auto triangle = new RightAngleTriangle("red", {0, 0}, {0, 3}, {4, 0});
    triangle->printFigureInfo();

    std::cout << "-------------------" << std::endl;

    auto circle = new Circle("blue", {0, 0}, {0, 3});
    circle->printFigureInfo();
    return 0;
}