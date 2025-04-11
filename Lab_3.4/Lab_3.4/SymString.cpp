#include "SymString.h"

ostream& operator<<(ostream& os, const SymString& obj) {
    os << obj.id << ": " << obj.value;
    return os;
}

SymString SymString::operator-(const SymString& other) {
    size_t pos = value.find(other.value);
    if (pos != string::npos) {
        value = value.substr(0, pos) + value.substr(pos + other.value.length());
    }
    else {
        cout << "Підрядок не знайдено. Повертається початковий рядок: " << value << endl;
    }
    return *this;
}