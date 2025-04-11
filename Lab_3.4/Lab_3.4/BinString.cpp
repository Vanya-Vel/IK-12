#include "BinString.h"

string BinString::operator-(const BinString& other) {
    int num1 = stoi(value, nullptr, 2);
    int num2 = stoi(other.value, nullptr, 2);
    int result = num1 - num2;

    string resultBin;
    if (result <= 0) {
        resultBin = "0000";
    }
    else {
        while (result > 0) {
            resultBin = to_string(result % 2) + resultBin;
            result /= 2;
        }

        // Доповнення до кратності 4
        int remainder = resultBin.length() % 4;
        if (remainder != 0) {
            int zerosToAdd = 4 - remainder;
            resultBin = string(zerosToAdd, '0') + resultBin;
        }
    }

    cout << "Результат в двійковому вигляді: " << resultBin << "\n";
    return resultBin;
}