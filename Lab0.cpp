#include <iostream>
#include <cmath>
#include <stdexcept>

// Абстрактний клас, що представляє трикутник
class AbstractTriangle {
protected:
    double a, b, c;  // Сторони трикутника

public:
    // Конструктор класу
    AbstractTriangle(double sideA, double sideB, double sideC) : a(sideA), b(sideB), c(sideC) {}

    // Чисто віртуальні функції, які будуть реалізовані в похідних класах
    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;
    virtual void printState() const = 0;

    // Функція для перевірки чи можна побудувати трикутник з заданими сторонами
    virtual bool isTriangle() const {
        return (a + b > c) && (b + c > a) && (c + a > b);
    }
};

// Похідний клас для рівностороннього трикутника
class EquilateralTriangle : public AbstractTriangle {
public:
    // Конструктор класу
    EquilateralTriangle(double side) : AbstractTriangle(side, side, side) {}

    // Реалізація віртуальних функцій
    double getArea() const override {
        double s = getPerimeter() / 2;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }

    double getPerimeter() const override {
        return 3 * a;
    }

    void printState() const override {
        std::cout << "Equilateral Triangle: Side Length = " << a << ", Area = " << getArea() << ", Perimeter = " << getPerimeter() << std::endl;
    }
};

// Похідний клас для рівнобедреного трикутника
class IsoscelesTriangle : public AbstractTriangle {
public:
    // Конструктор класу
    IsoscelesTriangle(double equalSide, double base) : AbstractTriangle(equalSide, equalSide, base) {}

    // Реалізація віртуальних функцій
    double getArea() const override {
        double s = getPerimeter() / 2;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }

    double getPerimeter() const override {
        return a + b + c;
    }

    void printState() const override {
        std::cout << "Isosceles Triangle: Equal Side Length = " << a << ", Base Length = " << c << ", Area = " << getArea() << ", Perimeter = " << getPerimeter() << std::endl;
    }
};

// Похідний клас для прямокутного трикутника
class RightTriangle : public AbstractTriangle {
public:
    // Конструктор класу
    RightTriangle(double leg1, double leg2) : AbstractTriangle(leg1, leg2, sqrt(leg1 * leg1 + leg2 * leg2)) {}

    // Реалізація віртуальних функцій
    double getArea() const override {
        return 0.5 * a * b;
    }

    double getPerimeter() const override {
        return a + b + c;
    }

    void printState() const override {
        std::cout << "Right Triangle: Leg1 = " << a << ", Leg2 = " << b << ", Hypotenuse = " << c << ", Area = " << getArea() << ", Perimeter = " << getPerimeter() << std::endl;
    }
};

int main() {
    const int numOfTriangles = 3;
    AbstractTriangle* triangles[numOfTriangles];

    try {
        // Створення об'єктів трикутників різних типів
        triangles[0] = new EquilateralTriangle(5.0);
        triangles[1] = new IsoscelesTriangle(4.0, 6.0);
        triangles[2] = new RightTriangle(3.0, 4.0);

        // Виведення інформації про трикутники
        for (int i = 0; i < numOfTriangles; ++i) {
            // Перевірка чи можна побудувати трикутник
            if (triangles[i]->isTriangle()) {
                triangles[i]->printState();
            }
            else {
                // Якщо трикутник не можна побудувати, викидаємо виняток
                throw std::invalid_argument("Invalid triangle sides");
            }
        }
    }
    catch (const std::invalid_argument& e) {
        // Обробка винятку, якщо трикутник не можна побудувати
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // Звільнення пам'яті від створених об'єктів
    for (int i = 0; i < numOfTriangles; ++i) {
        delete triangles[i];
    }

    return 0;
}
