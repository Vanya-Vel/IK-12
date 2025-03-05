#pragma once
#include <iostream>
#include <string>
using namespace std;

class Post
{
private:
    string mainMailbox;  // Основна частина поштової адреси
    string domain;       // Домен поштової адреси
    string MailAddresses[10];  // Масив для зберігання поштових адрес
    int currentCount = 0;  // Лічильник кількості заповнених поштових адрес

public:
    // Геттери та сеттери для роботи з основною частиною поштової адреси та доменом
    string getMainMailbox() const { return mainMailbox; }
    void setMainMailbox(const string& value) { mainMailbox = value; }
    string getDomain() const { return domain; }
    void setDomain(const string& value) { domain = value; }

    // Геттер для отримання конкретної поштової адреси для юніт тесту
    string getMailAddress(int index) {
        if (index < 0 || index >= currentCount) {
            return "Invalid index";  // Захист від виходу за межі масиву
        }
        return MailAddresses[index];
    }

    void menu();  // Головне меню програми
    void AddPost();  // Додавання нової поштової адреси
    void AddPostForTest(); // Додатковий метод для тестування без вводу від користувача
    void DeletePost(int index);  // Видалення поштової адреси за індексом
    void RenameDomain(int index);  // Зміна домену для певної адреси
    void RenameMainMailbox(int index);  // Зміна основної частини поштової адреси
    void ListPost();  // Вивід усіх збережених поштових адрес
};
