#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "SortedSinglyLinkedList.h"
using namespace std;

class Application
{
private:
	int cmd;

	ifstream InFile;
	ofstream OutFile;
	SortedSinglyLinkedList<UserType> LinkedList;
public:
	Application();
	~Application();

	void Run();
	int GetCommand();

	void InsertUser();
	void DeleteUser();
	void UpdateUser();
	void SearchById();
	void SearchByName();
	void PrintAllUser();

	int OpenInFile(string fileName);
	int OpenOutFile(string fileName);

	int ReadDataFromFile();
	int WriteDataFromFile();

	void SearchInListById(UserType& user);
	void SearchInListByName(UserType& user);
};

Application::Application()
{
	cmd = -1;
}
Application::~Application()
{}

void Application::Run()
{
	while (1)
	{
		cmd = GetCommand();

		switch (cmd)
		{
		case 1:
			InsertUser();
			break;
		case 2:
			DeleteUser();
			break;
		case 3:
			UpdateUser();
			break;
		case 4:
			LinkedList.MakeEmpty();
			break;
		case 5:
			SearchById();
			break;
		case 6:
			SearchByName();
			break;
		case 7:
			PrintAllUser();
			break;
		case 8:
			ReadDataFromFile();
			break;
		case 9:
			WriteDataFromFile();
			break;
		case 0:
			return;
		default:
			GetCommand();
			break;
		}
	}
}

int Application::GetCommand()
{
	cout << "------ Unsorted Array List ------" << endl;
	cout << "-- 1. Insert User" << endl;
	cout << "-- 2. Delete User" << endl;
	cout << "-- 3. Update User" << endl;
	cout << "-- 4. Make Empty List" << endl;
	cout << "-- 5. Search by Id" << endl;
	cout << "-- 6. Search by Name" << endl;
	cout << "-- 7. Print All User" << endl;
	cout << "-- 8. Load Data from File" << endl;
	cout << "-- 9. Save Data to File" << endl;
	cout << "-- 0. Back" << endl;
	cout << "----------------------------" << endl;
	cout << "-- Choose number you run : ";
	cin >> cmd;

	return cmd;
}

void Application::InsertUser()
{
	UserType data;

	data.SetAllFromKB();
	LinkedList.Insert(data);
}
void Application::DeleteUser()
{
	UserType user;
	cout << "���� ";
	user.SetIdFromKB();

	if (LinkedList.Delete(user))
		cout << "���� �Ϸ�" << endl;
	else
		cout << "��ġ�ϴ� �׸� ����" << endl;
}
void Application::UpdateUser()
{
	UserType user;
	cout << "������ �׸��� ";
	user.SetIdFromKB();

	if (!LinkedList.Get(user))
	{
		cout << "��ġ�ϴ� �׸� ����" << endl;
		return;
	}
	else
	{
		cout << "��, ID�� �ٲٽ� �� �����ϴ�." << endl;
		user.SetAllFromKB();
		if (LinkedList.Update(user))
			cout << "������Ʈ ����" << endl;
		else
			cout << "������Ʈ ����" << endl;
	}
}
void Application::SearchById()
{
	UserType user;
	cout << "ã�� ";
	user.SetIdFromKB();
	SearchInListById(user);
}
void Application::SearchByName()
{
	UserType user;
	cout << "ã�� ";
	user.SetNameFromKB();
	SearchInListByName(user);
}
void Application::PrintAllUser()
{
	UserType user;

	cout << "----- ���� ��� -----" << endl;
	LinkedList.ResetList();
	for (int i = 0; i < LinkedList.GetLength(); i++)
	{
		LinkedList.GetNextUser(user);
		user.PrintAll();
	}
}

int Application::OpenInFile(string fileName)
{
	InFile.open(fileName);

	if (!InFile)
		return 0;
	else
		return 1;
}
int Application::OpenOutFile(string fileName)
{
	OutFile.open(fileName);

	if (!OutFile)
		return 0;
	else
		return 1;
}

int Application::ReadDataFromFile()
{
	int index = 0;
	UserType user;

	string fileName;
	cout << "���� �̸��� �Է��ϼ��� : ";
	getline(cin, fileName);

	if (!OpenInFile(fileName))
		return 0;

	while (!InFile.eof())
	{
		user.ReadDataFromFile(InFile);
		LinkedList.Insert(user);
	}

	InFile.close();
	return 1;
}
int Application::WriteDataFromFile()
{
	UserType user;

	string fileName;
	cout << "���� �̸��� �Է��ϼ��� : ";
	getline(cin, fileName);

	if (!OpenOutFile(fileName))
		return 0;

	LinkedList.ResetList();

	for (int i = 0; i < LinkedList.GetLength(); i++)
	{
		user.WriteDataFromFile(OutFile);
		LinkedList.GetNextUser(user);
	}

	OutFile.close();

	return 1;
}

void Application::SearchInListById(UserType& user)
{
	UserType temp;
	LinkedList.ResetList();

	int count = 0;
	for (int i = 0; i < LinkedList.GetLength(); i++)
	{
		if (temp.GetId().find(user.GetId()) != -1)
		{
			temp.PrintAll();
			count++;
		}
		LinkedList.GetNextUser(temp);
	}
	if (count == 0)
		cout << "ã�� �� �����ϴ�." << endl;
}
void Application::SearchInListByName(UserType& user)
{
	UserType temp;
	LinkedList.ResetList();

	int count = 0;
	for (int i = 0; i < LinkedList.GetLength(); i++)
	{
		if (temp.GetName().find(user.GetName()) != -1)
		{
			temp.PrintAll();
			count++;
		}
		LinkedList.GetNextUser(temp);
	}
	if (count == 0)
		cout << "ã�� �� �����ϴ�." << endl;
}