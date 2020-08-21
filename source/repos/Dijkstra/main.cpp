/*
... iss Crew
... Made By Mukho
... 2020-08-21 FRI
... Dijkstra
*/

/*
	Dijkstra Algorithm using Priority Queue( O(N * log N) )
		- ��� ������ heap�� �־� ���� ���� ��θ� ���� ������ �������� ����.
		- Linear Search�� Recursion�� �̿��ϴ� ����� �ִ�.( O(N^2) )
*/

// ������(1)���� �� �������� ���� '�ִ� ���' ���ϱ�
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int number = 6;
int INF = 1000000;

vector<pair<int, int>> a[7]; // ���� ����
int d[7]; // �ּ� ���

void dijkstra(int start) {
	d[start] = 0; // ������
	priority_queue<pair<int, int> > pq; // Heap

	pq.push(make_pair(start, 0)); // ������
	// ����� ������� ó���ϱ� ������ Queue�� ���
	while (!pq.empty()) {
		int current = pq.top().first; // ���� ��ġ
		int distance = -pq.top().second; // ª�� ���� ���� ������ ����ȭ
		pq.pop();

		if (d[current] < distance) continue; // �ִ� �Ÿ��� �ƴ� ��� ��ŵ
		for (int i = 0; i < a[current].size(); i++) {
			int next = a[current][i].first; // ���õ� ����� ���� ���
			int nextDistance = distance + a[current][i].second; // ���õ� ��带 ���� ����� ���ļ� ���� ���

			// ������ �ּ� ��뺸�� �� �����ϴٸ� ��ü
			if (nextDistance < d[next]) {
				d[next] = nextDistance;
				pq.push(make_pair(next, -nextDistance));
			}
		} 
	}
}

int main() {
	for (int i = 1; i <= number; i++)
		d[i] = INF; // ������� ���� ��� ����� �������� ó��
	
	a[1].push_back(make_pair(2, 2));
	a[1].push_back(make_pair(3, 5));
	a[1].push_back(make_pair(4, 1));

	a[2].push_back(make_pair(1, 2));
	a[2].push_back(make_pair(3, 3));
	a[2].push_back(make_pair(4, 2));

	a[3].push_back(make_pair(1, 5));
	a[3].push_back(make_pair(2, 3));
	a[3].push_back(make_pair(4, 3));
	a[3].push_back(make_pair(5, 1));
	a[3].push_back(make_pair(6, 5));

	a[4].push_back(make_pair(1, 1));
	a[4].push_back(make_pair(2, 2));
	a[4].push_back(make_pair(3, 3));
	a[4].push_back(make_pair(5, 1));

	a[5].push_back(make_pair(3, 1));
	a[5].push_back(make_pair(4, 1));
	a[5].push_back(make_pair(6, 2));

	a[6].push_back(make_pair(3, 5));
	a[6].push_back(make_pair(5, 2));

	// �������� 1
	dijkstra(1);

	for (int i = 1; i <= number; i++)
		cout << d[i] << ' ';
	cout << endl;
}