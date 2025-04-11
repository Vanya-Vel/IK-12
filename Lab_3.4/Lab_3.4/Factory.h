#pragma once
#include "SymString.h"
#include "BinString.h"

const int MAX_OBJECTS = 100;

class Factory : public BinString {
private:
    SymString* symStrings[MAX_OBJECTS];
    BinString* binStrings[MAX_OBJECTS];
    int symCount;
    int binCount;

public:
    Factory(const string& id = "", const string& value = "")
        : BinString(id, value), symCount(0), binCount(0) {}

    ~Factory();

    void createSymString(const string& id, const string& value);

    void createBinString(const string& id, const string& value);

    void showAll() const;

    void deleteObject(int index);

    SymString* getSymString(int index) {
        return (index >= 0 && index < symCount) ? symStrings[index] : nullptr;
    }

    BinString* getBinString(int index) {
        int binIndex = index - symCount;
        return (binIndex >= 0 && binIndex < binCount) ? binStrings[binIndex] : nullptr;
    }
};
