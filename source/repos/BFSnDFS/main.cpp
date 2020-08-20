/*
... iss Crew
... Made By Mukho
... 2020-08-20 THU
... Breadth First Search and Depth First Search
*/

/*
	�ʺ�켱Ž��(BFS) : �ڽŰ� ����� �ֺ� �������� Ž��.
						���̰� ���� �׷������� ���� ������ ����.
						���̰� ���� �׷������� ���� ������ ����.
						Queue�� �����. Tree�� Level-Order�� ����
						������� ���� O(v^2), ��������Ʈ ���� O(V+E)

						0. �������� queue�� push.
						1. queue�� ���� �տ� �ִ� ��带 pop
						2. ���� ��忡 ������ ��� ���� �� ���� �湮���� ���� ������ queue�� push
						3. queue�� ������� ������, 1������ �ٽ� ����

	���̿켱Ž��(DFS) : ������ �ϳ� ������ ����� ��� ������ ������ Ž��.
						���̰� ���� �׷������� ���� ������ ����.
						���̰� ���� �׷������� ���� ������ ����.
						Stack �Ǵ� ��͸� �����. Tree�� Inorder�� ����
						������� ���� O(v^2), ��������Ʈ ���� O(V+E)
*/

#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

#define MAXV 8

vector<int> adj[MAXV]; // �׷����� ���� ���踦 ��������Ʈ�� ����
int visitB[MAXV]; // ��� i�� �湮�� ���� ������ 1, ������ 0
int visitD[MAXV]; // ��� i�� �湮�� ���� ������ 1, ������ 0
int visitD2[MAXV]; // ��� i�� �湮�� ���� ������ 1, ������ 0

void BFS(int start);
void DFS(int start); // recursion
void DFS2(int start); // stack
int main() {
	// A-B
	adj[1].push_back(2);
	adj[2].push_back(1);
	// A-C
	adj[1].push_back(3);
	adj[3].push_back(1);
	// A-D
	adj[1].push_back(4);
	adj[4].push_back(1);
	// B-E
	adj[2].push_back(5);
	adj[5].push_back(2);
	// B-F
	adj[2].push_back(6);
	adj[6].push_back(2);
	// C-G
	adj[3].push_back(7);
	adj[7].push_back(3);
	/*
	            1
		2		3		4
	   5 6       7

	   BFS -> 1 2 3 4 5 6 7
	   DFS -> 1 2 5 6 3 7 4
	*/

	BFS(1); // 1�� ������ BFS ����
	DFS(1); // 1�� ������ DFS(���) ����
	cout << endl;
	DFS2(1); // 1�� ������ DFS(stack) ����
	

	return 0;
}

void BFS(int start) {
	queue<int> q;
	q.push(start);
	visitB[start] = 1;

	while (!q.empty()) {
		int x = q.front(); // ���
		q.pop();
		cout << x << ' ';

		for (int i = 0; i < adj[x].size(); i++) { // �� ��忡 �ڽ� ������ ������ push
			int y = adj[x][i];
			if (!visitB[y]) {
				q.push(y);
				visitB[y] = 1;
			}
		}
	}
	cout << endl;
}

void DFS(int start) {
	if (visitD[start])
		return;

	visitD[start] = 1;
	cout << start << ' ';

	for (int i = 0; i < adj[start].size(); i++) {
		int x = adj[start][i];
		DFS(x);
	}
}

void DFS2(int start) {
	stack<int> s;
	s.push(start);
	visitD2[start] = 1;
	cout << start << ' ';
	
	while (!s.empty()) {
		int x = s.top();
		s.pop();
		for (int i = 0; i < adj[x].size(); i++) {
			int y = adj[x][i];
			if (!visitD2[y]) {
				cout << y << ' ';
				visitD2[y] = 1;
				s.push(x);
				s.push(y);
				break;
			}
		}
	}
	cout << endl;
}