#include <iostream>
#include <fstream>
#include <string>
#include "LinkedList.h"
using namespace std;

class Application
{
private:
	int command;
	LinkedList<ItemType> List;
public:
	Application();
	~Application();

	void Run();
	int GetCommand(int number);

	void Insert();
	void Delete();
	void Update();
	void Show();
	void Search();
};

Application::Application()
{
	command = -1;
}
Application::~Application()
{
	List.MakeEmpty();
}

void Application::Run()
{
	while (1)
	{
		command = GetCommand(command);
		switch (command)
		{
		case 1:
			Insert();
			break;
		case 2:
			Delete();
			break;
		case 3:
			Update();
			break;
		case 4:
			Show();
			break;
		case 5:
			Search();
			break;
		case 0:
			return;
			break;
		default:
			break;
		}
	}
}
int Application::GetCommand(int number)
{
	cout << "1. �߰�" << endl;
	cout << "2. ����" << endl;
	cout << "3. ����" << endl;
	cout << "4. ���" << endl;
	cout << "5. �˻�" << endl;
	cout << "0. ����" << endl;
	cout << "�Է� : ";
	cin >> number;

	return number;
}

void Application::Insert()
{
	ItemType item;
	item.SetAllByKB();
	List.Insert(item);
}
void Application::Delete()
{
	ItemType item;
	item.SetAllByKB();
	List.Delete(item);
}
void Application::Update()
{
	ItemType item;
	cout << "������ item�� �Է��ϼ���." << endl;
	item.SetAllByKB();
	if (List.Get(item))
	{
		cout << "��, ���̸� �ٲ� �� �ֽ��ϴ�." << endl;
		item.SetAgeByKB();
		List.Update(item);
	}
	else
		cout << "������ �����͸� ã�� �� �����ϴ�." << endl;
}
void Application::Show()
{
	ItemType item;

	List.ResetPointer();
	for(int i=0;i<List.GetLength();i++)
	{
		List.GetNextItem(item);
		item.ShowAll();
	}
}
void Application::Search()
{
	ItemType item;

	cout << "�˻��� item�� �̸��� �Է��ϼ���." << endl;
	item.SetNameByKB();

	ItemType temp;
	List.ResetPointer();
	for (int i = 0; i < List.GetLength(); i++)
	{
		List.GetNextItem(temp);
		if (temp.GetName().find(item.GetName()) != -1)
			temp.ShowAll();
	}
}