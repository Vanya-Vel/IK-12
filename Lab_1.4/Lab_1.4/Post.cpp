#include "Post.h"

// ���� ��� �����䳿 � ������������
void Post::menu()
{
    int choice = 0;  // ����������� ������ �����������
    do {
        // ��������� ����
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
            AddPost();  // ��������� ���� �����
            break;
        case 2:
            int index;
            cout << "Enter the index to delete: ";
            cin >> index;
            DeletePost(index);  // ��������� ������� ������ �� ��������
            break;
        case 3:
            cout << "Enter the index to rename domain: ";
            cin >> index;
            RenameDomain(index);  // ���� ������
            break;
        case 4:
            cout << "Enter the index to rename main mailbox: ";
            cin >> index;
            RenameMainMailbox(index);  // ���� ������� ������� ������
            break;
        case 5:
            ListPost();  // ��������� ������ ��� �����
            break;
        case 6:
            cout << "Exiting...\n";  // ����� � ��������
            break;
        default:
            cout << "Invalid choice! Please try again.\n";  // ����������� ����
            break;
        }
    } while (choice != 6);  // ����������, ���� ���������� �� ������ Exit
}

// ��������� ���� ������� ������ ����� �������� �����������
void Post::AddPost()
{
    if (currentCount < 10) {  // �������� �� ����������� ������� �����
        cout << "Enter the main mailbox: ";
        cin >> mainMailbox;
        cout << "Enter the domain: ";
        cin >> domain;
        MailAddresses[currentCount] = mainMailbox + "@" + domain;  // �������� �����
        currentCount++;  // �������� ��������
    }
    else {
        cout << "Mailbox limit reached!" << endl;  // ���� ��������� ����
    }
}

// ��������� ������� ������ �� ��������
void Post::DeletePost(int index)
{
    if (index < 0 || index >= currentCount) {
        cout << "Invalid index!" << endl;  // �������� �������
        return;
    }

    // ��������� �������� ���� �������� ������ �� ���� ������� ����
    for (int i = index; i < currentCount - 1; i++) {
        MailAddresses[i] = MailAddresses[i + 1];
    }

    // ������� ������� �������
    MailAddresses[currentCount - 1] = "";
    currentCount--;  // �������� ��������
    cout << "Post address at index " << index << " has been deleted!" << endl;
}

// ���� ������ ��� ������� ������� ������
void Post::RenameDomain(int index)
{
    if (index < 0 || index >= currentCount) {
        cout << "Invalid index!" << endl;  // �������� �������
        return;
    }

    string newDomain;
    cout << "Enter new domain: ";
    cin >> newDomain;  // ������� ����� �����

    MailAddresses[index] = mainMailbox + "@" + newDomain;  // ��������� ������
    cout << "Domain changed successfully!" << endl;
}

// ���� ������� ������� ������� ������
void Post::RenameMainMailbox(int index)
{
    if (index < 0 || index >= currentCount) {
        cout << "Invalid index!" << endl;  // �������� �������
        return;
    }

    string newMail;
    cout << "Enter new mailbox name: ";
    cin >> newMail;  // ������� ���� ������� ������� ������

    MailAddresses[index] = newMail + "@" + domain;  // ��������� ������� ������� ������
    cout << "Mailbox name changed successfully!" << endl;
}

// ��������� ��� ���������� �������� �����
void Post::ListPost()
{
    for (int j = 0; j < currentCount; j++) {
        cout << "Current email address: " << j + 1 << ". " << MailAddresses[j] << endl;  // ��������� ������
    }
}

// ��������� �������� ����� ��� ���-����� ��� �������� �����������
void Post::AddPostForTest()
{
    if (currentCount < 10) {
        MailAddresses[currentCount] = mainMailbox + "@" + domain;  // ��������� ������� ������
        currentCount++;  // �������� ��������
    }
}
