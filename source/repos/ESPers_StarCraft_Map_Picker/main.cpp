/*
... iss Crew
... Made by Mukho
... 2020-06-17 Wed
... ESPers_StarCraft_Map_Picker
*/
// �� �����̴ϱ� ���� ����.
#pragma warning(disable : 6385) // ����..?
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

int main()
{
	string map[7] = {"Destination(2)", "Match Point(2)", "Neo Sylphid(3)", "Tau Cross(3)", "Fighting Spirit(4)", "Cirucit Breaker(4)", "Escalade(4)"}; // �� ���
	string picked_map[5]; // ����� ���� ������ �迭
	int order[5]; // �� ������ ������ �迭

	int ban_Player1, ban_Player2; // ���� ���� ��ȣ�� ����� ����

	// �� ��� ���
	cout << "�ڸ� ���" << endl;
	for (int i = 0; i < 7; i++)
		cout << i + 1 << " : " << map[i] << endl;
	cout << endl;

	// ù��° �÷��̾��� �� ��
	while (1)
	{
		cout << "ù��°�� ���� ���� ��ȣ�� �Է����ּ��� : ";
		cin >> ban_Player1;
		if (ban_Player1 < 1 or ban_Player1 > 7) // �߸��� ���� �Է�
			cout << "!�߸��� ��ȣ�Դϴ�." << endl;
		else
			break;
	}

	// �ι�° �÷��̾��� �� ��
	while (1)
	{
		cout << "�ι�°�� ���� ���� ��ȣ�� �Է����ּ��� : ";
		cin >> ban_Player2;
		if (ban_Player2 < 1 or ban_Player2 > 7) // �߸��� ���� �Է�
			cout << "!�߸��� ��ȣ�Դϴ�." << endl;
		else
			if (ban_Player1 == ban_Player2) // �� �ߺ� ��
				cout << "!�Ȱ��� ���� ���߽��ϴ�." << endl;
			else
				break;
	}
	// map �迭���� ������ �뵵�� ���� ��ȯ
	ban_Player1--;
	ban_Player2--;

	int temp = 0; // ����� ����
	for (int i = 0; i < 7; i++)
	{
		if (i == ban_Player1 or i == ban_Player2)
			continue; // ��� ���� Pass
		picked_map[temp++] = map[i]; // �� ����
	}

	// �� ���� ���ϱ�
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 5; i++)
	{
		int number = rand()%5; // ���� ����
		order[i] = number;
		for (int j = 0; j < i; j++)
			if (order[i] == order[j]) // �ߺ��� ��� ���� �ٽ� ����
			{
				i--;
				break;
			}
	}
	
	// �� ���� ���
	cout << endl << "�ڸ� ����" << endl;
	for (int i = 0; i < 5; i++)
		cout << "  " << i + 1 << "Set : " << picked_map[order[i]] << endl;
	cout << endl;

	system("pause");
	return 0;
}