#include <iostream>
#include <sstream>

struct Complex {
    Complex() {}
    explicit Complex(const double real); // поможет избежать неявного преобразования типов данных
    Complex(const double real, const double imaginary);

    double re = 0.0;
    double im = 0.0;

    bool operator==(const Complex& rhs) const {return (re == rhs.re) && (im == rhs.im); }
    bool operator!=(const Complex& rhs) const {return !operator==(rhs); }
 // Оператор должен быть константным иначе мы не сможем складывать комплексные числа в которых левый аргумент был константным комплексным числом,
 // потому что этот оператор является членом класса.
 // Его нельзя вызывать от константных объектов


    /*
     * Оператор += должен быть членом класса, потому что он берёт имеющийся объект класса и его модифицирует причём не константным членом класса
     * Оператор += должен возвращать ссылку на себя
     */
    Complex& operator+=(const Complex& rhs) {
        re += rhs.re;
        im += rhs.im;
        return *this;
    }
};
    /*
    Если нам нужно определить бинарные операторы арифметические или операторы сравнения, то рекомендуется их объявлять вне класса не надо делать их членами класса,
    Потому что мы упускаем возможность для левого аргумента быть не объектом класса. Оператор становится не симметричным правый аргумент получается можно прикастовать, а левый нельзя
    */
    // Return Value Optimization
     Complex operator+(const Complex& lhs, const Complex& rhs) {
         Complex result = lhs;
         result += rhs;
         return result;
     }

int main() {

    return 0;
}