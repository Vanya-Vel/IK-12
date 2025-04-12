#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_3.6/D3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab36
{
	TEST_CLASS(UnitTestLab36)
	{
	public:
		
        TEST_METHOD(TestMethodB1_Show)
        {
            // ��������� ��'��� ����� B1 � �������� �������� 777 ��� �����������
            B1 b1(777);

            // ��������������� ����������� ���� ��������� (std::cout) � ��������� ����
            std::stringstream output;
            std::streambuf* oldCoutStreamBuf = std::cout.rdbuf(output.rdbuf()); // �������� ������ ����� ��� ���������

            // ��������� ������� show_B1, ��� ������ ���������� �� ����������� ����
            b1.show_B1();

            // ³��������� ����������� ���� ��������� ���� ���������� �����
            std::cout.rdbuf(oldCoutStreamBuf); // ��������� ���� ��������� �����

            // ����������, �� �������� ��������� �������� � output
            // ������ ������� "B1::b1 = 777" � ���������� ������
            Assert::IsTrue(output.str().find("B1::b1 = 777") != std::string::npos);
        }
        ''
	};
}
