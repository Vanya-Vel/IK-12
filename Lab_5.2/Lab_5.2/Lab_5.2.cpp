// Lab_05_2.cpp
// < Величко Іван >
// Лабораторна робота № 5.2
// Класи з опрацюванням виняткових ситуацій
// Варіант 0.4


#include <iostream>
#include <stdexcept>  // Для стандартних винятків
#include <exception>  // Для перевизначення std::exception
#include <cstdlib>    // Для exit()
#include <windows.h>

// --- Класи винятків ---

// Порожній клас
class MyEmptyException {};

// Незалежний клас з полями
class MyIndependentException {
public:
    int hours, minutes;
    MyIndependentException(int h, int m) : hours(h), minutes(m) {}
};

std::string to_string(int value) {
    char buffer[32] = { 0 };
    std::snprintf(buffer, sizeof(buffer), "%d", value);
    return std::string(buffer);
}

class MyDerivedException : public std::exception {
    int hours, minutes;
    std::string message;
public:
    MyDerivedException(int h, int m)
        : hours(h), minutes(m) {
        message = "Invalid time: " + to_string(hours) + ":" + to_string(minutes);
    }

    const char* what() const noexcept override {
        return message.c_str();
    }
};

// --- Функції перетворення годин і хвилин у секунди ---

// Варіант 1: без специфікації
int convertToSeconds1(int hours, int minutes) {
    if (hours < 0 || hours > 23 || minutes < 0 || minutes > 59)
        throw "Invalid time";
    return (hours * 3600 + minutes * 60);
}

// Варіант 2: із специфікацією throw()
int convertToSeconds2(int hours, int minutes) throw() {
    if (hours < 0 || hours > 23 || minutes < 0 || minutes > 59)
        throw "Invalid time";
    return (hours * 3600 + minutes * 60);
}

// Варіант 3: конкретна специфікація стандартного винятку
int convertToSeconds3(int hours, int minutes) throw(std::invalid_argument) {
    if (hours < 0 || hours > 23 || minutes < 0 || minutes > 59)
        throw std::invalid_argument("Invalid time");
    return (hours * 3600 + minutes * 60);
}

// Варіант 4: специфікація з порожнім власним винятком
int convertToSeconds4(int hours, int minutes) throw(MyEmptyException) {
    if (hours < 0 || hours > 23 || minutes < 0 || minutes > 59)
        throw MyEmptyException();
    return (hours * 3600 + minutes * 60);
}

// Варіант 5: специфікація з незалежним класом
int convertToSeconds5(int hours, int minutes) throw(MyIndependentException) {
    if (hours < 0 || hours > 23 || minutes < 0 || minutes > 59)
        throw MyIndependentException(hours, minutes);
    return (hours * 3600 + minutes * 60);
}

// Варіант 6: специфікація з класом-нащадком std::exception
int convertToSeconds6(int hours, int minutes) throw(MyDerivedException) {
    if (hours < 0 || hours > 23 || minutes < 0 || minutes > 59)
        throw MyDerivedException(hours, minutes);
    return (hours * 3600 + minutes * 60);
}

// --- Перевизначення terminate() і unexpected() ---

void myTerminate() {
    std::cerr << "Немає обробника винятку. Завершення програми.\n";
    std::exit(1);
}

void myUnexpected() {
    std::cerr << "Несподіваний виняток. Завершення програми.\n";
    std::exit(1);
}

// --- Головна функція ---

int main() {
    // Встановлення кодування для кирилиці
    SetConsoleOutputCP(1251);  // Для виведення кирилиці в Windows

    std::set_terminate(myTerminate);
    std::set_unexpected(myUnexpected);

    int hours, minutes, choise;
    std::cout << "Введіть години і хвилини (через пробіл): ";
    std::cin >> hours >> minutes;

    try {

        std::cout << "Виберіть функцію для тестування:\n";
        std::cout << "1. Переведення часу (години, хвилини) в секунди без обробки винятків\n";
        std::cout << "2. Переведення часу (години, хвилини) в секунди з винятками типу throw()\n";
        std::cout << "3. Переведення часу (години, хвилини) в секунди з стандартними винятками\n";
        std::cout << "4. Переведення часу (години, хвилини) в секунди з власним винятком\n";
        std::cout << "5. Переведення часу (години, хвилини) в секунди з власним винятком (інші умови)\n";
        std::cout << "6. Переведення часу (години, хвилини) в секунди з обробкою винятків std::out_of_range\n";
        std::cout << "7. Переведення часу (години, хвилини) в секунди всіма функціями\n";
        std::cout << "Виберіть функцію (1-7): \n";
        std::cin >> choise;

        int seconds = 0; // Оголошуємо до switch

        switch (choise) {
        case 1:
            seconds = convertToSeconds1(hours, minutes);
            break;
        case 2:
            seconds = convertToSeconds2(hours, minutes);
            break;
        case 3:
            seconds = convertToSeconds3(hours, minutes);
            break;
        case 4:
            seconds = convertToSeconds4(hours, minutes);
            break;
        case 5:
            seconds = convertToSeconds5(hours, minutes);
            break;
        case 6:
            seconds = convertToSeconds6(hours, minutes);
            break;
        case 7:
            try {
                std::cout << "1. Переведення часу (години, хвилини) в секунди без обробки винятків\n";
                seconds = convertToSeconds1(hours, minutes);
                std::cout << "Result from convertToSeconds1: " << seconds << " секунд\n";
            }
            catch (const char* msg) {
                std::cout << "Error in convertToSeconds1: " << msg << std::endl << std::endl;
            }

            try {
                std::cout << "2. Переведення часу (години, хвилини) в секунди з винятками типу throw()\n";
                seconds = convertToSeconds2(hours, minutes);
                std::cout << "Result from convertToSeconds2: " << seconds << " секунд\n";
            }
            catch (const char* msg) {
                std::cout << "Error in convertToSeconds2: " << msg << std::endl << std::endl;
            }

            try {
                std::cout << "3. Переведення часу (години, хвилини) в секунди з стандартними винятками\n";
                seconds = convertToSeconds3(hours, minutes);
                std::cout << "Result from convertToSeconds3: " << seconds << " секунд\n";
            }
            catch (const std::invalid_argument& e) {
                std::cout << "Error in convertToSeconds3: " << e.what() << std::endl << std::endl;
            }

            try {
                std::cout << "4. Переведення часу (години, хвилини) в секунди з власним винятком\n";
                seconds = convertToSeconds4(hours, minutes);
                std::cout << "Result from convertToSeconds4: " << seconds << " секунд\n";
            }
            catch (const MyEmptyException&) {
                std::cout << "Error in convertToSeconds4: MyEmptyException - Invalid time." << std::endl << std::endl;
            }

            try {
                std::cout << "5. Переведення часу (години, хвилини) в секунди з власним винятком (інші умови)\n";
                seconds = convertToSeconds5(hours, minutes);
                std::cout << "Result from convertToSeconds5: " << seconds << " секунд\n";
            }
            catch (const MyIndependentException& e) {
                std::cout << "Error in convertToSeconds5: MyIndependentException - Invalid time: " << e.hours << ":" << e.minutes << std::endl << std::endl;
            }

            try {
                std::cout << "6. Переведення часу (години, хвилини) в секунди з обробкою винятків std::out_of_range\n";
                seconds = convertToSeconds6(hours, minutes);
                std::cout << "Result from convertToSeconds6: " << seconds << " секунд\n";
            }
            catch (const MyDerivedException& e) {
                std::cout << "Error in convertToSeconds6: MyDerivedException - " << e.what() << std::endl << std::endl;
            }
            break;

        default:
            std::cout << "Невірний вибір функції!" << std::endl;
            return 1;
        }

        std::cout << "Час у секундах: " << seconds << std::endl;
    }
    catch (const MyDerivedException& e) {
        std::cerr << "Помилка (MyDerivedException): " << e.what() << std::endl;
    }
    catch (const MyIndependentException& e) {
        std::cerr << "Помилка (MyIndependentException): неправильний час "
            << e.hours << ":" << e.minutes << std::endl;
    }
    catch (const MyEmptyException&) {
        std::cerr << "Помилка (MyEmptyException): неправильний час." << std::endl;
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Помилка (std::invalid_argument): " << e.what() << std::endl;
    }
    catch (const char* msg) {
        std::cerr << "Помилка (char*): " << msg << std::endl;
    }
    catch (...) {
        std::cerr << "Невідома помилка.\n";
        throw; // Викличе terminate()
    }

    return 0;
}
