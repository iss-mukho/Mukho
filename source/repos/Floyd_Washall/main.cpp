/*
... iss Crew
... Made By Mukho
... 2020-08-21 FRI
... Floyd Warshall
*/

/*
	Floyd Warshall
		- '��� ����'���� '��� ����'������ �ִ� ��θ� ���ϰ� �ʹٸ� ���
		- ����� ���̰� '����'�� ��쿡�� ��� ����
		- ���İ��� ������ �������� �˰����� ����
		- 3�� for���� ���� ���� ����. O(V^3) -> �ӵ� ����
		- Dynamic Programming
		https://m.blog.naver.com/PostView.nhn?blogId=ndb796&logNo=221234427842&proxyReferer=https:%2F%2Fwww.google.com%2F
*/

#include <iostream>
using namespace std;

int number = 4;
int INF = 10000000;

// �ڷ� �迭 �ʱ�ȭ
int a[4][4] = {
	{0, 5, INF, 8},
	{7, 0, 9, INF},
	{-1, INF, 0, 4},
	{INF, INF, 3, 0}
};

void Floyd_Warshall() {
	int d[4][4]; // ��� �׷��� �ʱ�ȭ
	for (int i = 0; i < number; i++)
		for (int j = 0; j < number; j++)
			d[i][j] = a[i][j];

	// m = ���İ��� ���(������), s = ��� ���, e = ���� ���
	for (int m = 0; m < number; m++)
		for (int s = 0; s < number; s++) {
			for (int e = 0; e < number; e++)
				if (d[s][e] > d[s][m] + d[m][e])
					d[s][e] = d[s][m] + d[m][e];
		}

	// ��� ���
	for (int i = 0; i < number; i++) {
		for (int j = 0; j < number; j++) 
			cout << d[i][j] << ' ';
		cout << endl;
	}
}

int main() {
	Floyd_Warshall();

	return 0;
}