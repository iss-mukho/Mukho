/*
... iss Crew
... Made By Mukho
... 2020-08-19 WEN
... Divide and Conquer
... Dynamic Programming
*/

/*
	Divide and Conquer(���� ������)
		- �־��� ������ ���� ��ʷ� ������, ������ ���� �������� �ذ��Ͽ� �����ϴ� ���.
		- Top-Down ���(����� ���� ���)
		1. ���� ��ʸ� �ϳ� �̻��� ���� ��ʷ� �����Ѵ�.
		2. ���� ��ʵ��� ���� �����Ѵ�.(��ʰ� ����� ���� ���� �̻� ��͸� ����Ѵ�.)
		3. �ʿ�� ���� ��ʵ��� ������ ���� ����� ���� ���Ѵ�.

		- ���� : ������ �������ν� ����� ������ �ذ� ����.
			   : ���������� ���� �ذ��ϴµ� ������ ����.
		- ���� : ��� �Լ� ȣ��� ���� overhead �߻�.
		       : ���ÿ� �پ��� ������ �����ϰ� �־�� �ϹǷ� Stack Overflow�� �߻��ϰų� ������ �޸� ����� ����.
		
		- ���� : Binary Search, �ִ밪 ã��, Merge Sort, Quick Sort, ...

		* Sudo Code
		Function F(x):
			If F(x) is Simple Then return 'F(x)�� ���'
			Else:
				x -> x1, x2
				Call F(x1), F(x2)
				return F(x1), F(x2)�� ���

		* Binary Search 1
		void Binary_Search(vector<int> v, int start, int end, int key) {
			if (start > end) return;
	
			int mid = (start + end) / 2;
			if (key == v[mid]) {
				cout << key << "�� " << mid << " �� �ִ�." << endl;
				return;
			}
			else {
				if (key < v[mid])
					Binary_Search(v, start, mid - 1, key);
				else
					Binary_Search(v, mid + 1, end, key);
			}
		}

		* Binary Search 2
		int Binary_Search(int target) {
			int low = 0;
			int high = v.size() - 1;

			while (low <= high) {
				int mid = (low + high) / 2;
				if (target == v[mid]) return mid; // found
				else if (target < v[mid]) low = mid + 1;
				else high = mid - 1;
			}
			return -1; // not found
		}

		* �ִ밪 ã��
		int findMax(vector<int> v, int start, int end) {
			if (start == end) return v[start]; // found
	
			int mid = (start + end) / 2;
			// divide
			int left = findMax(v, start, mid);
			int right = findMax(v, mid + 1, end);

			return (left > right) ? left : right;
		}
*/

/*
	Dynamic Programming(���� ��ȹ��)
		- ������ ������ ������ ���� ���� ������ ������ Ǫ�� ���
		- ��ü ������ ���� ������ �ܼ�ȭ�� ����, ��ȭ������ ����� ������� ������ Ȱ��, ��ü ������ �ذ��ϴ� ���
		- ���ʿ��� ����� ���̰�, ȿ�������� �����ظ� ã�� �� ����
		- ���� ������ ���� ���ϱ޼������� ������ �� �����ϴ�.
		
		1. �ܼ�ȭ(divide)
		2. ��ȭ�� ����(recursion �̿�)
		3. �ذ�(conquer)

		- �ִ� ��� ����, ����� ���� ���� ���� ����ȭ�� ���ȴ�.
		- Memoization : �Լ��� ���� ����� ��, �� ���� �迭�� �����ϴ� ���.

		- Dynamic Programming : �ణ�� �ð��� �ɸ�. ��, �츮�� �� �� �ִ� ��� ��Ȳ�� ���� ��ü�� ���� �����Ͽ� ������ ��θ� ã�Ƴ�.
		- Greedy Algorithm : ��ȿ���� ����. ��, ��ü���� ��Ȳ�� ������� �ʰ�, �������� �����ΰ� ���� ������ ���� ���� ��θ� �˻��Ͽ� ã��.

		����) �Ǻ���ġ ����

			������ �Լ��� ������ ����.
				function fib(n)
					if n = 0
						return 0
					else if n=1
						return 1 
					else
						return fib(n-1) + fib(n-2)
			- �ߺ��Ǵ� ����� �����ϱ� ������( ����. level 3. (fib(3) + fib(2)) + (fib(2) + fib(1)) ), ��ü���� ��� �ӵ��� ��������. �� �˰����� �ð� ���⵵�� ���� �Լ�( O(2^N) )�� �ȴ�.
			- �� �Լ��� ��갪�� �����ϴ� ��ü�� ����ϸ� �ߺ� ����� �پ���, �ð� ���⵵�� O(n)�� �ȴ�.
				var m := map(0 �� 1, 1 �� 1) // Memoization

				function fib(n)
					if n not in keys(m)
						m[n] := fib(n-1) + fib(n-2)
					return m[n]
*/

// �Ǻ���ġ ���� DP(���, �ݺ���)���� ���ϱ�
#include <iostream>
using namespace std;

// DP_���
int Fib(int n) {
	int* data;
	data = new int[n + 1];

	data[0] = 0;
	data[1] = 1;

	if (data[n] > 0 || (n == 0)) return data[n];
	return Fib(n - 1) + Fib(n - 2);
}
// DP_�ݺ���
int fib(int n) {
	int* data;
	data = new int[n + 1];

	data[0] = 0;
	data[1] = 1;

	if (n > 1)
		for (int i = 2; i <= n; i++)
			data[i] = data[i - 2] + data[i - 1];

	return data[n];
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int num;
	while (1) {
		cout << "���� �Է� : ";
		cin >> num;
		if (num < 0) break;
		else
			cout << fib(num) << "\n"; // �ݺ���
			cout << Fib(num) << "\n"; // DP
			// �ݺ��� O(n), DP O(n). �ݺ����� �� ������
			// ����� ����� �� �������̴�.
	}

	return 0;
}