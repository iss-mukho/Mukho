/*
... iss Crew
... Made By Mukho
... 2020-06-26 FRI
... Sorting 1/2
*/
#include <iostream>
using namespace std;

#define SIZE 10

void Bubble_Sort(int list[], int size);
void Selection_Sort(int list[], int size); // �� ����Ŭ�� �� �� �ּҰ��� ã�� �� �� ���� ��ü.
void Insertion_Sort(int list[], int size); // �� ���� ���� ��, ���� ����� ���� �� ���� ��ġ�� ã�� ���� ��ü��.

void BinarySearch(int list[], int size, int key);
void BinarySearchRecursion(int list[], int first, int last, int key);
void LinearSearch(int list[], int size, int key);

int main()
{
	// �迭 ����
	int arr1[SIZE] = { 2, 6, 3, 8, 15, 30, 1, 9, 27, 16 }; // Do Binary Search after Bubble Sort
	int arr2[SIZE] = { 2, 6, 3, 8, 15, 30, 1, 9, 27, 16 }; // Do Binary Search with Recursion after Selection Sort
	int arr3[SIZE] = { 2, 6, 3, 8, 15, 30, 1, 9, 27, 16 }; // Do Linear Search after Insertion Sort

	// ���� �� �迭 ���
	cout << "���� �� �迭 ���" << endl;
	cout << "arr1 : ";
	for (int i = 0; i < SIZE; i++)
		cout << arr1[i] << ' ';
	cout << endl;
	cout << "arr2 : ";
	for (int i = 0; i < SIZE; i++)
		cout << arr2[i] << ' ';
	cout << endl;
	cout << "arr3 : ";
	for (int i = 0; i < SIZE; i++)
		cout << arr3[i] << ' ';
	cout << endl << endl;

	// ����
	Bubble_Sort(arr1, SIZE);
	Selection_Sort(arr2, SIZE);
	Insertion_Sort(arr3, SIZE);

	// ���� �� �迭 ���
	cout << "���� �� �迭 ���" << endl;
	cout << "arr1 : ";
	for (int i = 0; i < SIZE; i++)
		cout << arr1[i] << ' ';
	cout << endl;
	cout << "arr2 : ";
	for (int i = 0; i < SIZE; i++)
		cout << arr2[i] << ' ';
	cout << endl;
	cout << "arr3 : ";
	for (int i = 0; i < SIZE; i++)
		cout << arr3[i] << ' ';
	cout << endl << endl;

	// �˻�
	cout << "�˻�" << endl;
	cout << "Binary Search�� �̿��� 16�� 17�� ã��" << endl;
	BinarySearch(arr1, SIZE, 16);
	BinarySearch(arr1, SIZE, 17);
	cout << endl;
	cout << "Recursion�� �̿��� Binary Search�� �̿��� 9�� 28�� ã��" << endl;
	BinarySearchRecursion(arr2, 0, SIZE, 9);
	BinarySearchRecursion(arr2, 0, SIZE, 28);
	cout << endl;
	cout << "Linear Search�� �̿��� 27�� 5�� ã��" << endl;
	LinearSearch(arr3, SIZE, 27);
	LinearSearch(arr3, SIZE, 5);
	cout << endl;

	return 0;
}

void Bubble_Sort(int list[], int size)
{
	for (int i = 0; i < size; i++)
		for (int j = 1; j < size; j++)
			if (list[j - 1] > list[j])
			{
				int temp = list[j-1];
				list[j-1] = list[j];
				list[j] = temp;
			}
}
void Selection_Sort(int list[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		int minIndex = i;
		for (int j = i+1; j < size; j++)
			if (list[j] < list[minIndex])
				minIndex = j;
		if (i != minIndex)
		{
			int temp = list[i];
			list[i] = list[minIndex];
			list[minIndex] = temp;
		}
	}
}
void Insertion_Sort(int list[], int size)
{
	int i = 0, j = 0;
	for (i = 1; i < size; i++)
	{
		int CurData = list[i];
		for (j = i - 1; j >= 0; j--)
		{
			if (list[j] > CurData)
				list[j + 1] = list[j];
			else
				break;
		}
		list[j + 1] = CurData; // for������ -1�� �Ǿ ����.
	}
}


void BinarySearch(int list[], int size, int key)
{
	int first = 0, last = size - 1, mid;
	bool found = false;
	while (first <= last)
	{
		mid = (first + last) / 2;
		if (list[mid] == key)
		{
			cout << key << "�� index�� " << mid << endl;
			found = true;
			break;
		}
		else if (list[mid] > key)
			last = mid - 1;
		else
			first = mid + 1;
	}

	if (found == false)
		cout << key << "�� ���� ã�� �� ����." << endl;
}
void BinarySearchRecursion(int list[], int first, int last, int key)
{
	if (first > last)
	{
		cout << key << "�� ���� ã�� �� ����." << endl;
		return;
	}
	int mid = (first + last) / 2;

	if (list[mid] == key)
	{
		cout << key << "�� index�� " << mid << endl;
		return;
	}
	else if (list[mid] > key)
		BinarySearchRecursion(list, first, mid - 1, key);
	else
		BinarySearchRecursion(list, mid + 1, last, key);

}
void LinearSearch(int list[], int size, int key)
{
	bool found = false;
	for (int i = 0; i < size; i++)
	{
		if (list[i] == key)
		{
			cout << key << "�� index�� " << i << endl;
			found = true;
			break;
		}
	}
	if (found == false)
		cout << key << "�� ���� ã�� �� ����." << endl;
}