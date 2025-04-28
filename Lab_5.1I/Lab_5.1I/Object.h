#pragma once

class Object
{
private:
    static unsigned int count;

public:
    // Повертає кількість створених об'єктів
    static unsigned int Count()
    {
        return count;
    }

    // Скидає лічильник до 0
    static void Reset()
    {
        count = 0;
    }

    // Конструктор — збільшує лічильник
    Object()
    {
        count++;
    }

    // Деструктор — зменшує лічильник
    virtual ~Object()
    {
        count--;
    }
};
