#include <iostream>
#include <string>
#include "Stack.h"

int main() {
    std::cout << "=== Stack<int> ===\n";
    try {
        Stack<int> s_int(2);
        s_int.push(10);
        s_int.push(20);
        std::cout << "Top element: " << s_int.top() << std::endl;

        // Переповнення
        s_int.push(30);  // Очікується виняток
    }
    catch (const std::exception& e) {
        std::cerr << "[int] Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Stack<double> ===\n";
    try {
        Stack<double> s_double(2);
        s_double.push(3.14);
        s_double.push(6.28);
        std::cout << "Top element: " << s_double.top() << std::endl;
        s_double.pop();   // Видаляє 6.28
        s_double.pop();   // Видаляє 3.14
        s_double.pop();   // Викине std::underflow_error
    }
    catch (const std::exception& e) {
        std::cerr << "[double] Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Stack<std::string> ===\n";
    try {
        Stack<std::string> s_str(2);
        s_str.push("Hello");
        s_str.push("World");
        std::cout << "Top element: " << s_str.top() << std::endl;
        s_str.pop();
        s_str.pop();

        // Звернення до top порожнього стеку
        std::cout << "Top element: " << s_str.top() << std::endl;  // Очікується виняток
    }
    catch (const std::exception& e) {
        std::cerr << "[string] Exception: " << e.what() << std::endl;
    }

    return 0;
}
