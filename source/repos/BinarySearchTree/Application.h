#include <iostream>
#include <fstream>
#include <string>
#include "BinarySearchTree.h"
using namespace std;

class Application
{
private:
	int command;
	BinarySearchTree<ItemType> Tree;
public:
	Application();
	~Application();

	void Run();
	int GetCommand(int number);

	void Insert();
	void Delete();
	void Update();
	void ShowPre();
	void ShowIn();
	void ShowPost();
	void Search();
};

Application::Application()
{
	command = -1;
}
Application::~Application()
{
	Tree.MakeEmpty();
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
			ShowPre();
			break;
		case 4:
			ShowIn();
			break;
		case 5:
			ShowPost();
			break;
		case 6:
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
	cout << "3. Preorder ���" << endl;
	cout << "4. Inorder ���" << endl;
	cout << "5. Postorder ���" << endl;
	cout << "6. �˻�" << endl;
	cout << "0. ����" << endl;
	cout << "�Է� : ";
	cin >> number;

	return number;
}

void Application::Insert()
{
	ItemType item;
	item.SetAllByKB();
	Tree.InsertItem(item);
}
void Application::Delete()
{
	ItemType item;
	item.SetAllByKB();
	Tree.DeleteItem(item);
}
void Application::Update()
{
	ItemType item;
	cout << "������ item�� �Է��ϼ���." << endl;
	item.SetAllByKB();
	
	bool found;
	Tree.SearchItem(item, found);
	if (found == true)
		item.ShowAll();
	else
		cout << "ã�� �� �����ϴ�." << endl;
}
void Application::ShowPre()
{
	Tree.PrintPre(cout);
}
void Application::ShowIn()
{
	Tree.PrintIn(cout);
}
void Application::ShowPost()
{
	Tree.PrintPost(cout);
}

void Application::Search()
{
	ItemType item;
	cout << "ã�� item�� �̸��� �Է��ϼ���. ";
	item.SetNameByKB();

	bool found;
	Tree.SearchItem(item, found);
	if (found == true)
	{
		item.ShowAll();
	}
	else
		cout << "����� ����" << endl;
}