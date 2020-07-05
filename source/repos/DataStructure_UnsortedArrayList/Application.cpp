#include "Application.h"

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
			uList.MakeEmpty();
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
	uList.Insert(data);
}
void Application::DeleteUser()
{
	UserType user;
	cout << "���� ";
	user.SetIdFromKB();

	if (uList.Delete(user))
		cout << "���� �Ϸ�" << endl;
	else
		cout << "��ġ�ϴ� �׸� ����" << endl;
}
void Application::UpdateUser()
{
	UserType user;
	cout << "������ �׸��� ";
	user.SetIdFromKB();

	if (!uList.Get(user))
	{
		cout << "��ġ�ϴ� �׸� ����" << endl;
		return;
	}
	else
	{
		if (uList.Update(user))
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
	uList.ResetIterator();
	int length = uList.GetLength();
	int curIndex = uList.GetNextUser(user);

	while (curIndex < length && curIndex != -1)
	{
		user.PrintAll();
		curIndex = uList.GetNextUser(user);
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
	cin.ignore();
	getline(cin, fileName);

	if (!OpenInFile(fileName))
		return 0;

	while (!InFile.eof())
	{
		user.ReadDataFromFile(InFile);
		uList.Insert(user);
	}

	InFile.close();
	return 1;
}
int Application::WriteDataFromFile()
{
	UserType user;

	string fileName;
	cout << "���� �̸��� �Է��ϼ��� : ";
	cin.ignore();
	getline(cin, fileName);

	if (!OpenOutFile(fileName))
		return 0;

	uList.ResetIterator();

	int length = uList.GetLength();
	int curIndex = uList.GetNextUser(user);
	while (curIndex < length && curIndex != -1)
	{
		user.WriteDataFromFile(OutFile);
		curIndex = uList.GetNextUser(user);
	}

	OutFile.close();

	return 1;
}

void Application::SearchInListById(UserType& user)
{
	UserType temp;
	uList.ResetIterator();

	int cur = uList.GetNextUser(temp), count = 0;
	while (cur < uList.GetLength() && cur != -1)
	{
		if (temp.GetId().find(user.GetId()) != -1)
		{
			temp.PrintAll();
			count++;
		}
		cur = uList.GetNextUser(temp);
	}
	if (count == 0)
		cout << "ã�� �� �����ϴ�." << endl;
}
void Application::SearchInListByName(UserType& user)
{
	UserType temp;
	uList.ResetIterator();

	int cur = uList.GetNextUser(temp), count = 0;
	while (cur < uList.GetLength() && cur != -1)
	{
		if (temp.GetName().find(user.GetName()) != -1)
		{
			temp.PrintAll();
			count++;
		}
		cur = uList.GetNextUser(temp);
	}
	if (count == 0)
		cout << "ã�� �� �����ϴ�." << endl;
}