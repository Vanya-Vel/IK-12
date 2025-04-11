#include "Factory.h"

Factory::~Factory() {
    for (int i = 0; i < symCount; ++i) delete symStrings[i];
    for (int i = 0; i < binCount; ++i) delete binStrings[i];
}

void Factory::createSymString(const string& id, const string& value) {
    if (symCount < MAX_OBJECTS) {
        symStrings[symCount++] = new SymString(id, value);
        cout << "��'��� SymString �������� ������!\n";
    }
}

void Factory::createBinString(const string& id, const string& value) {
    if (binCount < MAX_OBJECTS) {
        binStrings[binCount++] = new BinString(id, value);
        cout << "��'��� BinString �������� ������!\n";
    }
}

void Factory::showAll() const {
    cout << "\n������ ��'���� SymString:\n";
    if (symCount == 0) cout << "������� ��'���� SymString �� ��������.\n";
    else for (int i = 0; i < symCount; ++i) cout << i << ". " << *symStrings[i] << endl;

    cout << "\n������ ��'���� BinString:\n";
    if (binCount == 0) cout << "������� ��'���� BinString �� ��������.\n";
    else for (int i = 0; i < binCount; ++i) cout << i + symCount << ". " << *binStrings[i] << endl;
}

void Factory::deleteObject(int index) {
    if (index >= 0 && index < symCount) {
        delete symStrings[index];
        for (int i = index; i < symCount - 1; ++i) {
            symStrings[i] = symStrings[i + 1];
        }
        --symCount;
        cout << "��'��� SymString ��������.\n";
    }
    else if (index >= symCount && index < symCount + binCount) {
        int binIndex = index - symCount;
        delete binStrings[binIndex];
        for (int i = binIndex; i < binCount - 1; ++i) {
            binStrings[i] = binStrings[i + 1];
        }
        --binCount;
        cout << "��'��� BinString ��������.\n";
    }
    else {
        cout << "������� ������.\n";
    }
}