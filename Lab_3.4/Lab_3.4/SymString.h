#pragma once
#include <iostream>
#include <string>
using namespace std;

class SymString {
protected:
    string id;
    string value;

public:
    SymString(const string& id, const string& value) : id(id), value(value) {}

    string getId() const { return id; }
    string getValue() const { return value; }

    friend ostream& operator<<(ostream& os, const SymString& obj);

    SymString operator-(const SymString& other);

    void show() const {
        cout << id << ": " << value << endl;
    }
};
