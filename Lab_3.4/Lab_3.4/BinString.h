#pragma once
#include "SymString.h"

class BinString : public SymString {
public:
    BinString(const string& id, const string& value) : SymString(id, value) {}

    string operator-(const BinString& other);
};
