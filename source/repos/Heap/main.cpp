/*
... iss Crew
... Made By Mukho
... 2020-08-20 THU
... Heap
*/

/*
	Heap : ���� ���� Ʈ���� ��������, �θ� ���� �ڽ� ��尣�� �׻� ��Ұ��谡 �����ϴ� �ڷᱸ��(���� ���鰣���� ��Ұ��� ��� ����)
		   �θ� ��尡 �ڽ� ��庸�� �׻� ũ�� �ִ���(Max Heap), �׻� ������ �ּ���(Min Heap)
		   ��Ʈ ��忡�� �׻� ���� ũ�ų� ���� ���� ���� ������, �̸� �̿��� �켱 ���� ť(Priority Queue)�� ������ �����ϴ�.
		   
		   Max-Heap Example
								100
					19						36
			17				3		  25		   1
		2		7

			- ���� ���� Ʈ���� Array�� �����Ѵ�.
			- ������ ���� �ϱ� ���� index�� 1���� �����Ѵ�.
			- Ư�� ����� index�� n�̶� �ϸ�, �θ� ���� n/2, �ڽ� ���� n*2, n*2+1�� ������ �� �ִ�.
*/
#include <iostream>
#include <time.h>
using namespace std;

#define HEAP_SIZE 256
#define ARRAY_SIZE 10

int heap[HEAP_SIZE]; // min heap
int heap_count = 0; // heap ������ ����, �迭�� ���� �� ���Ҹ� ��Ÿ��

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
void init() {
	heap_count = 0;
}
int size() {
	return heap_count;
}
void push(int data) {
	heap[++heap_count] = data; // data �߰�

	// ���Ҹ� �ϳ��� �ø��� �κ�
	int child = heap_count; // ��� �߰��� data
	int parent = child / 2; // �߰��� node�� parent
	while (child > 1 && heap[parent] > heap[child]) { // parent�� �� ũ��(min heap�̱� ����)
		swap(&heap[parent], &heap[child]); // ��ü
		child = parent; // node�� �Ѵܰ� �÷��� �ݺ�
		parent = child / 2;
	}
}
int pop() {
	int result = heap[1]; // ù ���� ��ȯ

	swap(&heap[1], &heap[heap_count]); // ù ���Ҹ� ������ ���ҿ� �ٲ�
	heap_count--;

	// ���Ҹ� �ϳ��� ������ �κ�(�ٲ����� ������ �ؾ���)
	int parent = 1; // ��� ������ �� �ٲ��� ����
	int child = parent * 2; // ���� ������ left child
	if (child + 1 <= heap_count) // ��尡 child�� ������ �ִ°�
		child = (heap[child] < heap[child + 1]) ? child : child + 1; // left�� right �� �� ���� node�� ��
	while (child<=heap_count && heap[parent]>heap[child]) { // child�� parent���� �� ������ �´°�?
		swap(&heap[parent], &heap[child]); // ��ü

		parent = child; // node�� �Ѵܰ� ���缭 �ݺ�
		child = child * 2;
		if (child + 1 <= heap_count) // ��尡 child�� ������ �ִ°�
			child = (heap[child] < heap[child + 1]) ? child : child + 1; // left�� right �� �� ���� node�� ��
	}
	return result;
}
int main() {
	int arr[ARRAY_SIZE];

	// �����Լ��� ���� srand�� seed
	srand(unsigned(time(NULL)));

	for (int i = 0; i < ARRAY_SIZE; i++)
		arr[i] = rand() % 50 + 1; // �迭�� 1~50�� ������ �ʱ�ȭ -> �и� 99.9% Ȯ���� ���ĵ��� ���� ������ ���̴�.

	// heap�� ����
	for (int i = 0; i < ARRAY_SIZE; i++)
		push(arr[i]);

	// pop�ϸ鼭 ������ Ȯ��
	for (int i = 0; i < ARRAY_SIZE; i++)
		cout << pop() << ' ';
	cout << endl;

	return 0;
}

