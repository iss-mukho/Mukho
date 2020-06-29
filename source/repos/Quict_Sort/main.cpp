/*
... iss Cruw
... Made By Mukho
... 2020-06-28 SUN
... Quick Sort
*/
#include <iostream>
using namespace std;
#define SIZE 10
#define Swap(x, y, temp) ( temp=x, x=y, y=temp )

void QuickSort(int list[], int left, int right);
int partition(int list[], int left, int right);

int main()
{
	int arr[SIZE] = { 2, 7, 1, 25, 37, 5, 16, 12, 9, 36 };

	cout << "���� �� �迭 ���" << endl;
	for (int i = 0; i < SIZE; i++)
		cout << arr[i] << ' ';
	cout << endl << endl;

	// ����
	QuickSort(arr, 0, SIZE - 1);

	cout << "���� �� �迭 ���" << endl;
	for (int i = 0; i < SIZE; i++)
		cout << arr[i] << ' ';
	cout << endl;

	return 0;
}

void QuickSort(int list[], int left, int right)
{
	if (left < right)
	{
		int p = partition(list, left, right);

		QuickSort(list, left, p - 1);
		QuickSort(list, p + 1, right);
	}
}
int partition(int list[], int left, int right)
{
	int low = left;
	int high = right + 1;
	int pivot = list[left]; // �� ���� �����͸� pivot���� ����
	int temp;

	do
	{
		// low, high�� �̿��� pivot�� ���� ���� ���� ū ���� pivot �¿�� �и�
		do
		{
			low++; // low�� left + 1���� ����
		} while(low <= right && list[low] < pivot);
		// list[low]�� pivot���� ������ low ����

		do
		{
			high--; // high�� right���� ����
		} while (high >= left && list[high] > pivot);
		// list[high]�� pivot���� ũ�� high ����
		
		// low�� high�� �������� �ʾ����� list[low]�� list[high]�� ��ȯ(�� ��ȯ �ڵ�)
		if (low < high)
			Swap(list[low], list[high], temp);
	} while (low < high);

	// low�� high�� ���������� �ݺ��� �ۿ��� list[left]�� list[high]�� ��ȯ // pivot(list[left])�� �� ��ġ(high)�� ������ ������
	Swap(list[left], list[high], temp);

	return high; // pivot ��ġ ��ȯ
}