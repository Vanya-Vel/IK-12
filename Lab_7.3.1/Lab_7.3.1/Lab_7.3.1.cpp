#include <iostream>
#include <string>

using namespace std;

// Функція для підрахунку кількості арифметичних операторів, які зустрічаються лише один раз
int countUniqueOperators(const string& text) {
    char ops[4] = { '+', '-', '*', '/' };
    int counts[4] = { 0, 0, 0, 0 };

    for (char ch : text) {
        if (ch == '+') counts[0]++;
        else if (ch == '-') counts[1]++;
        else if (ch == '*') counts[2]++;
        else if (ch == '/') counts[3]++;
    }

    int uniqueCount = 0;
    for (int i = 0; i < 4; i++) {
        if (counts[i] == 1)
            uniqueCount++;
    }

    return uniqueCount;
}

int main() {
    string text;
    cout << "Введіть рядок: ";
    getline(cin, text);

    int result = countUniqueOperators(text);
    cout << "Кількість арифметичних операторів, які зустрічаються лише один раз: " << result << endl;

    return 0;
}
