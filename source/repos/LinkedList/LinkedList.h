#include "ItemType.h"

template <typename T>
struct Node
{
	T data;
	Node* next;
};

template <typename T>
class LinkedList
{
private:
	Node<T>* Head;
	Node<T>* CurPointer;
	int length;
public:
	LinkedList();
	~LinkedList();
	
	void MakeEmpty();

	int GetLength();
	void ResetPointer();
	void NextPointer();
	bool isEmpty();
	void GetNextItem(T& item);

	int Insert(T& item);
	int Delete(T& item);
	int Update(T& item);
	int Get(T& item);
};

template <typename T>
LinkedList<T>::LinkedList()
{
	Head = NULL;
	CurPointer = NULL;
	length = 0;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
	MakeEmpty();
}

template <typename T>
void LinkedList<T>::MakeEmpty()
{
	Node<T>* temp;
	while (Head != NULL)
	{
		temp = Head;
		Head = Head->next;
		delete temp;
	}
	length = 0;
}

template <typename T>
int LinkedList<T>::GetLength()
{
	return length;
}
template <typename T>
void LinkedList<T>::ResetPointer()
{
	CurPointer = NULL;
}
template <typename T>
void LinkedList<T>::NextPointer()
{
	if (CurPointer == NULL)
		CurPointer = Head;
	else
		CurPointer = CurPointer->next;
}
template <typename T>
bool LinkedList<T>::isEmpty()
{
	if (length == 0)
		return true;
	else
		return false;
}
template<typename T>
void LinkedList<T>::GetNextItem(T& item)
{
	NextPointer();
	item = CurPointer->data;
}
template <typename T>
int LinkedList<T>::Insert(T& item)
{
	ResetPointer();

	// ������ item�� ��忡 ����
	Node<T>* node = new Node<T>;
	node->data = item;
	node->next = NULL;

	// �����Ͱ� ���� ��
	if (!length)
		Head = node; // Head�� ����
	else
	{		
		while (1)
		{
			NextPointer();
			if (CurPointer->next == NULL)
				break;
		}
		CurPointer->next = node;
	}
	length++;
	return 1;
}
template <typename T>
int LinkedList<T>::Delete(T& item)
{
	bool success = false;
	Node<T>* pre;
	Node<T>* del;

	T temp; // �񱳿� �ӽú���

	ResetPointer();
	if (Get(item) == 0) return 0;

	while (1)
	{
		pre = CurPointer;
		GetNextItem(temp);

		if (temp == item) // ���� item�� ã�Ҵ�
		{
			if (pre == NULL)
			{
				del = Head;
				Head = Head->next;
				delete del;
			}
			else
			{
				del = CurPointer;
				pre->next = CurPointer->next;
				delete del;
			}
			length--;
			success = true;
			break;
		}
	}
	return success;
}
template <typename T>
int LinkedList<T>::Update(T& item)
{
	Node<T>* location;
	location = Head;

	bool success = false;
	bool MoreToSearch = (location != NULL);

	while (MoreToSearch && !success)
	{
		if (item == location->data)
		{
			location->data = item;
			success = true;
		}
		else
		{
			location = location->next;
			MoreToSearch = (location != NULL);
		}
	}

	return success;
}
template <typename T>
int LinkedList<T>::Get(T& item)
{
	Node<T>* location;
	location = Head;

	bool Found = false;
	bool MoreToSearch = (location != NULL);

	while (MoreToSearch && !Found)
	{
		if (item == location->data)
			Found = true;
		else
		{
			location = location->next;
			MoreToSearch = (location != NULL);
		}
	}

	return Found;
}