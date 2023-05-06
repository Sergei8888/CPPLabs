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
    std::vector<float> a_coords;
    std::vector<float> b_coords;
    std::vector<float> c_coords;

public:
    RightAngleTriangle(std::string color, std::vector<float> a_coords, std::vector<float> b_coords,
                       std::vector<float> c_coords) {
        this->color = std::move(color);
        this->a_coords = std::move(a_coords);
        this->b_coords = std::move(b_coords);
        this->c_coords = std::move(c_coords);
    }

    float area() override {
        float a = sqrt(pow(a_coords[0] - b_coords[0], 2) + pow(a_coords[1] - b_coords[1], 2));
        float b = sqrt(pow(b_coords[0] - c_coords[0], 2) + pow(b_coords[1] - c_coords[1], 2));
        float c = sqrt(pow(c_coords[0] - a_coords[0], 2) + pow(c_coords[1] - a_coords[1], 2));

        float p = (a + b + c) / 2;

        return sqrt(p * (p - a) * (p - b) * (p - c));
    }

    void printFigureInfo() override {
        std::cout << "Right angle triangle" << std::endl;
        std::cout << "Color: " << color << std::endl;
        std::cout << "A: " << a_coords[0] << " " << a_coords[1] << std::endl;
        std::cout << "B: " << b_coords[0] << " " << b_coords[1] << std::endl;
        std::cout << "C: " << c_coords[0] << " " << c_coords[1] << std::endl;
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