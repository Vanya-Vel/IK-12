#include "pch.h"
#include "CppUnitTest.h"
#include <iostream>
#include "../Lab_1.4/Post.h"
#include "../Lab_1.4/Post.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace UnitTestLab15
{
    TEST_CLASS(UnitTestLab15) // Клас для тестування
    {
    public:

        TEST_METHOD(TestAddPost) // Метод для тестування додавання пошти
        {
            // Створення об'єкта Post
            Post post;

            // Використання сеттерів для встановлення основної частини пошти та домену
            post.setMainMailbox("john");
            post.setDomain("example.com");

            // Викликаємо метод AddPostForTest для додавання нової поштової адреси без вводу користувача
            post.AddPostForTest();

            // Перевіряємо, чи було успішно додано поштову адресу
            // Ми припускаємо, що масив знаходиться в позиції 0 після першого додавання
            Assert::AreEqual(string("john@example.com"), post.getMailAddress(0));
        }
    };
}
