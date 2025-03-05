#include "Post.h"

// Меню для взаємодії з користувачем
void Post::menu()
{
    int choice = 0;  // Ініціалізація вибору користувача
    do {
        // Виведення меню
        cout << "\nMenu:\n";
        cout << "1. Add Post\n";
        cout << "2. Reset Post\n";
        cout << "3. Rename Domain\n";
        cout << "4. Rename Main Mailbox\n";
        cout << "5. List Post\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            AddPost();  // Додавання нової пошти
            break;
        case 2:
            int index;
            cout << "Enter the index to delete: ";
            cin >> index;
            DeletePost(index);  // Видалення поштової адреси за індексом
            break;
        case 3:
            cout << "Enter the index to rename domain: ";
            cin >> index;
            RenameDomain(index);  // Зміна домену
            break;
        case 4:
            cout << "Enter the index to rename main mailbox: ";
            cin >> index;
            RenameMainMailbox(index);  // Зміна основної частини адреси
            break;
        case 5:
            ListPost();  // Виведення списку всіх адрес
            break;
        case 6:
            cout << "Exiting...\n";  // Вихід з програми
            break;
        default:
            cout << "Invalid choice! Please try again.\n";  // Некоректний вибір
            break;
        }
    } while (choice != 6);  // Продовжуємо, поки користувач не вибере Exit
}

// Додавання нової поштової адреси через введення користувача
void Post::AddPost()
{
    if (currentCount < 10) {  // Перевірка на максимальну кількість адрес
        cout << "Enter the main mailbox: ";
        cin >> mainMailbox;
        cout << "Enter the domain: ";
        cin >> domain;
        MailAddresses[currentCount] = mainMailbox + "@" + domain;  // Зберігаємо пошту
        currentCount++;  // Збільшуємо лічильник
    }
    else {
        cout << "Mailbox limit reached!" << endl;  // Якщо досягнуто ліміту
    }
}

// Видалення поштової адреси за індексом
void Post::DeletePost(int index)
{
    if (index < 0 || index >= currentCount) {
        cout << "Invalid index!" << endl;  // Перевірка індексу
        return;
    }

    // Переміщаємо елементи після видаленої адреси на одну позицію вліво
    for (int i = index; i < currentCount - 1; i++) {
        MailAddresses[i] = MailAddresses[i + 1];
    }

    // Очищаємо останню позицію
    MailAddresses[currentCount - 1] = "";
    currentCount--;  // Зменшуємо лічильник
    cout << "Post address at index " << index << " has been deleted!" << endl;
}

// Зміна домену для вказаної поштової адреси
void Post::RenameDomain(int index)
{
    if (index < 0 || index >= currentCount) {
        cout << "Invalid index!" << endl;  // Перевірка індексу
        return;
    }

    string newDomain;
    cout << "Enter new domain: ";
    cin >> newDomain;  // Вводимо новий домен

    MailAddresses[index] = mainMailbox + "@" + newDomain;  // Оновлення домену
    cout << "Domain changed successfully!" << endl;
}

// Зміна основної частини поштової адреси
void Post::RenameMainMailbox(int index)
{
    if (index < 0 || index >= currentCount) {
        cout << "Invalid index!" << endl;  // Перевірка індексу
        return;
    }

    string newMail;
    cout << "Enter new mailbox name: ";
    cin >> newMail;  // Вводимо нову основну частину адреси

    MailAddresses[index] = newMail + "@" + domain;  // Оновлення основної частини адреси
    cout << "Mailbox name changed successfully!" << endl;
}

// Виведення всіх збережених поштових адрес
void Post::ListPost()
{
    for (int j = 0; j < currentCount; j++) {
        cout << "Current email address: " << j + 1 << ". " << MailAddresses[j] << endl;  // Виведення адреси
    }
}

// Додавання тестових даних для юніт-тестів без введення користувача
void Post::AddPostForTest()
{
    if (currentCount < 10) {
        MailAddresses[currentCount] = mainMailbox + "@" + domain;  // Додавання тестової адреси
        currentCount++;  // Збільшуємо лічильник
    }
}
