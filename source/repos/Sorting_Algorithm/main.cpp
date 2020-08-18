/*
... iss Crew
... Made By Mukho
... 2020-08-18 TUE
... Sorting and Search Algorithm
*/

#include <iostream>
#include <vector>
using namespace std;

/*
	���� ����(Selection Sort)
	- ���� ��ġ�� �� ���� ã�� �����ϴ� �˰���.
	- �ּ�/�ִ� ���� ���ķ� ���� ����.
	- 1. ���� ���� ���� index�� �� �տ�������, �̸� ������ �� ������ �迭�� �� ���� ���� ���� ã�´�.
	  2. ���� ���� ���� ã����, �� ���� ���� index�� ���� �ٲ۴�.
	  3. ���� index���� �� ������ �ݺ��Ѵ�.

	- �ð����⵵ : O(n^2) -> ������ ��ü ��
	- �������⵵ : O(1) -> �ϳ��� �迭������ ����
*/
void Selection_Sort(vector<int>& v); // ��ü �� �� �� ������ ����

/*
	���� ����(Insertion Sort)
	- ���� ��ġ����, �� ������ �迭���� ���� �ڽ��� �� ��ġ�� ã�� �� ��ġ�� �����ϴ� �˰���.
	- 1. 2��° index���� ������. ���� index�� ������ ������ �����ϰ�, �� index�� (���� index-1)�� ��´�.
	  2. ������ ���� ������ �� index�� �迭 ���� ���Ѵ�.
	  3. ���� ������ ���� �� ������ ���� index�� �� index�� ���� �������ְ�, �� index�� -1�Ͽ� �񱳸� �ݺ��Ѵ�.
	  4. ���� ���� ������ �� ũ��, �� index + 1�� ���� ������ �����Ѵ�.

	- �ð����⵵ : O(n^2) / (�ּ��� ���, �̹� ���ĵ� �迭���� ����-O(n)
	- �������⵵ : O(1)
*/
void Insertion_Sort(vector<int>& v); // �� ��(���ĵ� ��)�� ����� ��

/*
	���� ����(Bubble Sort)
	- �Ź� ���ӵ� �ΰ� �ε����� ���Ͽ�, ���� ������ ���� �ڷ� �Ѱ� �����ϴ� ���
	- 1. 2��° index���� ������. ���� index�� ������ ������ �����ϰ�, �� index�� (���� index-1)�� ��´�.
	  2. ������ ���� ������ �� index�� �迭 ���� ���Ѵ�.
	  3. ���� ������ ���� �� ������ ���� index�� �� index�� ���� �������ְ�, �� index�� -1�Ͽ� �񱳸� �ݺ��Ѵ�.
	  4. ���� ���� ������ �� ũ��, �� index + 1�� ���� ������ �����Ѵ�.

	- �ð����⵵ : O(n^2) -> ������ ��ü ��
	- �������⵵ : O(1)
*/
void Bubble_Sort(vector<int>& v); // ���پƾƾƾƾ� ���پƾƾƾ� ���پƾƾ� ���پƾ� ���� ��!

/*
	�պ� ����(Merge Sort)
	- ���� ����(Divide and Conquer) ������� ����� �˰���.
	- �Է����� �ϳ��� �迭�� �ް�, ���� �߿� �ΰ��� �迭�� ��� �ɰ� ���� ��, ��ġ�鼭 ������ ���Ŀ��� �ϳ��� ������ ���
	- 1. �ϳ��� �迭�� ������ �ɰ���. �迭�� ���� ��ġ�� ���� ��ġ�� �Է¹޾�, ���� ���� �� 2�� ���� ������ ��´�.
	  2. �̸� �ɰ� �迭�� ũ�Ⱑ 0�̰ų� 1�϶� ���� ���Ѵ�.
	- 1. �� �迭 A, B�� ũ�⸦ �豳�� ���� �迭�� ù index�� i, j�� ����.
	  2. A[i]�� B[j]�� ���� ���� ��(�������� ����)�� �� �迭 C�� ��������. ������ �迭�� index�� 1 ������Ų��.
	  3. 2���� ������ �� �迭�� ������ ������ �� ���� �ݺ��Ѵ�.
	  4. ���� �迭�� ���� ��� C�� �����Ѵ�.
	  5. C�� ���� �迭�� �����Ѵ�.

	- �ð����⵵ : O(N log N)
	- �������⵵ : O(N)
*/
void Merge_Sort(vector<int>& v, int start, int end);
void merge(vector<int>& v, int start, int end, int mid); // �պ� �Լ�

/*
	�պ� ����(Merge Sort)
	- ���� ����(Divide and Conquer) ������� ����� �˰���. ���Ұ� ������ ���ÿ� �Ѵ�.
	- pivot�̶� �ϴ� ������ �Ǵ� ���� �������� ���� ���� ���� ����, ū ���� ���������� �ű�� ������� ����.
	- 1. pivot ���� ���Ѵ�.
	  2. ���� ���� index�� ������ left ����, ���� ������ index�� ������ right ������ �����Ѵ�.
	  3. right����, right�� left���� Ŭ���� �ݺ��Ͽ� ���Ѵ�. ���� �迭���� pivot���� ũ�� right�� �ϳ� ���ҽ�Ű�� �񱳸� �ݺ��Ѵ�. pivot���� ���� �迭 ���� ã���� �ݺ��� �����Ѵ�.
	  4. �� ���� left����, right�� left���� Ŭ���� �񱳸� �����Ѵ�. ���� �迭���� pivot���� ������ left�� �ϳ� ������Ű�� �񱳸� �ݺ��Ѵ�. pivot���� ū �迭 ���� ã���� �ݺ��� �����Ѵ�.
	  5. left index ���� right index ���� �ٲ��ش�.
	  6. 3~5 ������ left<right�� ������ �� ���� �ݺ��Ѵ�.
	  7. �� ������ ������ left�� ���� pivot�� �ٲ��ش�.
	  8. �� ���ʺ��� left - 1����, left+1���� �� �����ʱ����� ���� Quick Sort�� �ݺ��Ѵ�.

	- �ð����⵵ : O(N log N) / (�־��� ��� - �̹� ���ĵǾ� �ִ� ��� O(N^2)
	- �������⵵ : O(log N)
*/
void Quick_Sort(vector<int>& v, int start, int end);

// ���� �˻�
void Linear_Search(vector<int> v, int key);
// ���� �˻�(��� ���)
void Binary_Search(vector<int> v, int start, int end, int key);

int main() {
	vector<int> select;
	vector<int> insert;
	vector<int> bubble;
	vector<int> merge;
	vector<int> quick;

	select.push_back(2);
	select.push_back(5);
	select.push_back(3);
	select.push_back(1);
	select.push_back(4);
	insert.push_back(2);
	insert.push_back(5);
	insert.push_back(3);
	insert.push_back(1);
	insert.push_back(4);
	bubble.push_back(2);
	bubble.push_back(5);
	bubble.push_back(3);
	bubble.push_back(1);
	bubble.push_back(4);
	merge.push_back(2);
	merge.push_back(5);
	merge.push_back(3);
	merge.push_back(1);
	merge.push_back(4);
	quick.push_back(2);
	quick.push_back(5);
	quick.push_back(3);
	quick.push_back(1);
	quick.push_back(4);

	// ���� �迭 ���
	cout << "select before : ";
	for (int i = 0; i < select.size(); i++)
		cout << select[i] << ' ';
	cout << endl;

	cout << "insert before : ";
	for (int i = 0; i < insert.size(); i++)
		cout << insert[i] << ' ';
	cout << endl;

	cout << "bubble before : ";
	for (int i = 0; i < bubble.size(); i++)
		cout << bubble[i] << ' ';
	cout << endl;

	cout << "merge before : ";
	for (int i = 0; i < merge.size(); i++)
		cout << merge[i] << ' ';
	cout << endl;

	cout << "quick before : ";
	for (int i = 0; i < quick.size(); i++)
		cout << quick[i] << ' ';
	cout << endl;

	cout << "* linear search 1 : ";
	Linear_Search(select, 1);
	cout << "* linear search 0 : ";
	Linear_Search(select, 0);
	cout << endl;

	// ����
	Selection_Sort(select);
	Insertion_Sort(insert);
	Bubble_Sort(bubble);
	Merge_Sort(merge, 0, merge.size() - 1);
	Quick_Sort(quick, 0, quick.size() - 1);

	// ���� �� �迭 ���
	cout << "select after : ";
	for (int i = 0; i < select.size(); i++)
		cout << select[i] << ' ';
	cout << endl;

	cout << "insert after : ";
	for (int i = 0; i < insert.size(); i++)
		cout << insert[i] << ' ';
	cout << endl;

	cout << "bubble after : ";
	for (int i = 0; i < bubble.size(); i++)
		cout << bubble[i] << ' ';
	cout << endl;

	cout << "merge after : ";
	for (int i = 0; i < merge.size(); i++)
		cout << merge[i] << ' ';
	cout << endl;

	cout << "quick after : ";
	for (int i = 0; i < quick.size(); i++)
		cout << quick[i] << ' ';
	cout << endl;

	cout << "* binary search 4 : ";
	Binary_Search(quick, 0, quick.size() - 1, 4);
	cout << "* binary search -1 : ";
	Binary_Search(quick, 0, quick.size() - 1, -1);
	cout << endl;

	return 0;
}

void Selection_Sort(vector<int>& v) {
	for (int i = 0; i < v.size() - 1; i++) {
		int minIdx = i;
		for (int j = i + 1; j < v.size(); j++)
			if (v[minIdx] > v[j])
				minIdx = j;
		swap(v[i], v[minIdx]);
	}
}

void Insertion_Sort(vector<int>& v) {
	for (int i = 1; i < v.size(); i++) {
		int key = v[i];
		int j = i - 1;
		for (j; j >= 0 && key < v[j]; j--)
			v[j + 1] = v[j]; // �� �̵� ->
		v[j + 1] = key; // �ش� ��ġ�� �� ����
	}
}

void Bubble_Sort(vector<int>& v) {
	for (int i = 0; i < v.size() - 1; i++)
		for (int j = 1; j < v.size(); j++)
			if (v[j - 1] > v[j])
				swap(v[j - 1], v[j]);
}

void Merge_Sort(vector<int>& v, int start, int end) {
	if (start < end) {
		int mid = (start + end) / 2;

		// ���� Divide
		Merge_Sort(v, start, mid);
		Merge_Sort(v, mid + 1, end);

		// �պ� Conquer
		merge(v, start, end, mid);
	}
}
void merge(vector<int>& v, int start, int end, int mid) {
	vector<int> temp;
	int i = start, j = mid + 1, tempIdx = 0;

	while (i <= mid && j <= end) {
		if (v[i] < v[j])
			temp.push_back(v[i++]);
		else
			temp.push_back(v[j++]);
	}

	while (i <= mid)
		temp.push_back(v[i++]);
	while (j <= end)
		temp.push_back(v[j++]);

	for (int k = start; k <= end; k++)
		v[k] = temp[tempIdx++];
}

void Quick_Sort(vector<int>& v, int start, int end) {
	int pivot = v[start]; // start�� �ϵ�, random���� �ϵ�, mid( (start+end)/2 )�� �ϵ� ����
	int left = start, right = end;

	// Partition start
	while (start < end) {
		while (pivot <= v[end] && start < end)
			end--; // <-
		while (pivot >= v[start] && start < end)
			start++; // ->

		swap(v[start], v[end]);
	}
	swap(v[left], v[start]);
	/*
		1. pivot�� �����Ѵ�.
		2. ������(end)���� �������� ���鼭 pivot���� ���� ���� ã�´�. (<- pivot���� ���� ù ��)
		3. ����(start)�������� ���������� ���鼭 pivot���� ū ���� ã�´�. (pivot���� ū ù �� ->)
		4. �� �ε��� start, end �� ���� ��Ҹ� ��ȯ�Ѵ�.

		5. 2, 3, 4�� ������ �ݺ��Ѵ�.
		6. 2, 3���� ���̻� ������ �� ���ٸ�, ���� pivot�� ��ȯ�Ѵ�.

		7. �� ��� ��ȯ�� pivot�� �������� ������ pivot���� ���� ������ �����ϰ�, �������� ū ������ �����Ѵ�.
		https://mygumi.tistory.com/308
	*/
	// Partition end

	if (left < start)
		Quick_Sort(v, left, start - 1);
	if (right > end)
		Quick_Sort(v, start + 1, right);

	/*
	  function quicksort(a, left, right)
	  if right > left then
		  select a pivot value a[pivotIndex]
		  pivotNewIndex := partition(a, left, right, pivotIndex)
		  quicksort(a, left, pivotNewIndex-1)
		  quicksort(a, pivotNewIndex+1, right)
	*/
}

void Linear_Search(vector<int> v, int key){
	for (int i = 0; i < v.size(); i++) {
		if (v[i] == key) {
			cout << key << " ���� " << i << " index�� �����Ѵ�." << endl;
			break;
		}
		if (i == v.size() - 1)
			cout << key << " ���� ã�� �� ����." << endl;
	}
}
void Binary_Search(vector<int> v, int start, int end, int key) {
	if (start > end) {
		cout << key << " ���� ã�� �� ����." << endl;
		return;
	}
	
	int mid = (start + end) / 2;
	if (v[mid] == key) {
		cout << key << " ���� " << mid << " index�� �����Ѵ�." << endl;
		return;
	}
	else if (v[mid] < key)
		Binary_Search(v, mid + 1, end, key);
	else
		Binary_Search(v, start, mid - 1, key);
}