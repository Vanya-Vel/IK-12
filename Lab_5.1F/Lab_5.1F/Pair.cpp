#include "Pair.h"

Pair::Pair() : first(0), second(0) {}

Pair::Pair(int first, int second) : first(first), second(second) {
    Exception();
}


Pair::Pair(const Pair& p) : first(p.first), second(p.second) {
    Exception();
}

bool Pair::Exception()
{
    try {
        if (first <= 0 || second <= 0) {
            // Генерація власного винятку
            // Генерація винятку для некоректного вибору
            try {
                throw PointException();
            }
            catch (PointException e) {
                cout << "[by value] Exception: " << e.what() << endl;              // Виняток за значенням
            }

            try {
                throw PointException();
            }
            catch (PointException& e) {
                cout << "[by reference] Exception: " << e.what() << endl;          // Виняток за посиланням
            }

            try {
                throw new PointException();
            }
            catch (PointException* e) {
                cout << "[by pointer] Exception: " << e->what() << endl;   // Виняток за вказівником
                delete e;
            }
            throw PointException();
        }
    }
    catch (const PointException& ex) {
        // Обробка винятку за посиланням
        cout << "Caught exception (by reference): " << ex.what() << endl;
        return false;  // Повертаємо false, щоб сигналізувати про помилку
    }
    return true;  // Повертаємо true, якщо все добре
}


std::istream& operator>>(std::istream& in, Pair& p) {
    std::cout << "Enter first value: ";
    in >> p.first;
    std::cout << "Enter second value: ";
    in >> p.second;
    return in;
}

std::ostream& operator<<(std::ostream& out, const Pair& p) {
    try {
        out << "First = " << p.first << ", Second = " << p.second;
        if (p.first <= 0 || p.second <= 0) {
            throw PointException();  // Генерація винятку для негативних значень
        }
    }
    catch (const PointException& ex) {
        std::cout << ex.what() << std::endl;  // Виведення помилки
    }
    return out;
}

std::string Pair::toString() const {
    return "First = " + std::to_string(first) + ", Second = " + std::to_string(second) + "\n";
}
