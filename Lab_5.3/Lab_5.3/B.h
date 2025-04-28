#pragma once
#include "A.h"

class B : public A {
public:
    B() { std::cout << "Конструктор B" << std::endl; }

    // Метод, що приймає копію об'єкта класу A
    void copyAndProcess(const A& a) {
        try {
            // Спроба привести до типу B
            const B& b = dynamic_cast<const B&>(a); // Операція приведення типу
            std::cout << "Приведено до типу B.\n";
            b.display();
        }
        catch (const std::bad_cast& e) {
            // Обробка винятку, якщо приведення типу неможливе
            std::cout << "Помилка приведення типу: " << e.what() << std::endl;
        }
    }

    void display() const override {
        std::cout << "Клас B" << std::endl;
    }
};

