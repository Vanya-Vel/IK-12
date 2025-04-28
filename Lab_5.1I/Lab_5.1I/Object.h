#pragma once

class Object
{
private:
    static unsigned int count;

public:
    // ������� ������� ��������� ��'����
    static unsigned int Count()
    {
        return count;
    }

    // ����� �������� �� 0
    static void Reset()
    {
        count = 0;
    }

    // ����������� � ������ ��������
    Object()
    {
        count++;
    }

    // ���������� � ������ ��������
    virtual ~Object()
    {
        count--;
    }
};
