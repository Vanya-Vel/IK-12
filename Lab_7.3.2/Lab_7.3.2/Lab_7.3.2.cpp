#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

// Функція: підраховує кількість арифметичних операторів, які зустрічаються рівно один раз
int countUniqueOperators(const string& text) {
    map<char, int> opCounts;

    const string operators = "+-*/";
    for (char ch : text) {
        if (operators.find(ch) != string::npos) {
            opCounts[ch]++;
        }
    }

    // Підрахунок скільки з них зустрічаються рівно один раз
    int count = count_if(opCounts.begin(), opCounts.end(),
        [](const pair<char, int>& p) { return p.second == 1; });

    return count;
}

int main() {
    string text;
    cout << "Введіть рядок: ";
    getline(cin, text);

    int result = countUniqueOperators(text);
    cout << "Кількість арифметичних операторів, які зустрічаються лише один раз: " << result << endl;

    return 0;
}
