#pragma once
#include <iostream>
#include <string>
using namespace std;

class Post
{
private:
    string mainMailbox;  // ������� ������� ������� ������
    string domain;       // ����� ������� ������
    string MailAddresses[10];  // ����� ��� ��������� �������� �����
    int currentCount = 0;  // ˳������� ������� ���������� �������� �����

public:
    // ������� �� ������� ��� ������ � �������� �������� ������� ������ �� �������
    string getMainMailbox() const { return mainMailbox; }
    void setMainMailbox(const string& value) { mainMailbox = value; }
    string getDomain() const { return domain; }
    void setDomain(const string& value) { domain = value; }

    // ������ ��� ��������� ��������� ������� ������ ��� ��� �����
    string getMailAddress(int index) {
        if (index < 0 || index >= currentCount) {
            return "Invalid index";  // ������ �� ������ �� ��� ������
        }
        return MailAddresses[index];
    }

    void menu();  // ������� ���� ��������
    void AddPost();  // ��������� ���� ������� ������
    void AddPostForTest(); // ���������� ����� ��� ���������� ��� ����� �� �����������
    void DeletePost(int index);  // ��������� ������� ������ �� ��������
    void RenameDomain(int index);  // ���� ������ ��� ����� ������
    void RenameMainMailbox(int index);  // ���� ������� ������� ������� ������
    void ListPost();  // ���� ��� ���������� �������� �����
};
