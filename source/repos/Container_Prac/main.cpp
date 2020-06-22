/*
... iss Crew
... Made By Mukgo
... 2020-06-22 MON
... Container Practice(vecter, list)
*/
#include <iostream>
#include <vector> // vector : ���� ���ٿ� ������
#include <list> // list : doubly linked list�� ������ ����. �߰� ������ ���� ������ ����
using namespace std;


bool P(int n)
{
	return (n <= 4);
}

int main()
{
	vector<int> vList; // ����ִ� vector vList�� ����
	// vector<int> vList(5); : �⺻��(0)���� �ʱ�ȭ �� 5���� ���Ҹ� ������ vector vList�� ����
	// vector<int> vList(5, 2); : 2�� �ʱ�ȭ �� 5���� ���Ҹ� ������ vector vList�� ����
	// vector<int> v2(v1); : v2�� v1�� �����ؼ� ����
	/*
	vList.assign(5, 0); // 0�� ������ 5���� ���� �Ҵ�
	vList.at(index); : index��° ���Ҹ� ����. ������ ������ ����
	vList[index]; : index��° ���Ҹ� ����. ����
	vList.front(); : �� �� ������ ����
	vList.back(); : �� �� ������ ����
	vList.push_back(22); : �� �ڿ� 22 ����
	vList.push_pop(); : �� �� ������ ����
	vList.clear(); : ��� ���Ҹ� ����. ��, �޸𸮴� �����ִ�.
	vList.begin(); == vList.rend(); : ù��° �����͸� ����Ŵ
	vList.end(); == vList.rbegin(); : ������ �������� ������ ����Ŵ

	vList.reserve(n); : n���� �����͸� ������ ��ġ�� �̸� �����Ҵ� ��
	vList.resize(n); : ũ�⸦ n���� ����, �� Ŀ���� ��� 0���� �ʱ�ȭ
	vList.resize(n, 3); ũ�⸦ n���� ����, �� Ŀ���� ��� 3���� �ʱ�ȭ
	vList.size(); : �������� ������ ����
	vList.capacity(); : �Ҵ�� ������ ũ�⸦ ����
	v2.swap(v1); : �����͸� ���� �ٲ�

	vList.insert(2,3,4); : 2��° ��ġ�� 4�� 3�� ����
	vList.insert(2,3); : 2��° ��ġ�� 3�� ����
	vList.erase(index); : index��°�� �����͸� ����
	vList.empty(); vector�� ������� true
	*/
	
	cout << "��VECTOR" << endl << endl;
	cout << "1 3 2 100 22 ���� �� �� ������ ������ ����" << endl;
	vList.push_back(1);
	vList.push_back(3);
	vList.push_back(2);
	vList.push_back(100);
	vList.push_back(22);
	vList.pop_back();

	// �ϴ� ���
	cout << "vList[i]�ð� vList.at(i) �÷� ���� ���" << endl;
	for (int i = 0; i < vList.size(); i++)
		cout << vList[i] << " ";
	cout << endl;
	for (int i = 0; i < vList.size(); i++)
		cout << vList.at(i) << " ";
	cout << endl << endl;

	cout << "ũ�� : " << vList.size() << endl;
	cout << "ù��° : " << vList.front() << endl;
	cout << "������ : " << vList.back() << endl;
	cout << endl << endl;

	cout << "3��° ��ġ�� 5 ���� �� ù��° ��ġ�� ������ ����" << endl;
	vList.insert(vList.begin() + 3, 5);
	vList.erase(vList.begin() + 0);
	cout << "ũ�� : " << vList.size() << endl;
	for (int i = 0; i < vList.size(); i++)
		cout << vList.at(i) << " ";
	cout << endl << endl;

	cout << "���� ����Ʈ �ʱ�ȭ" << endl;
	vList.clear();
	cout << "ũ�� : " << vList.size() << endl;
	for (int i = 0; i < vList.size(); i++)
		cout << vList.at(i) << " ";
	cout << endl << endl << endl << "------------------------------------------------------" << endl;

	cout << "��LIST" << endl << endl;
	list<int> lList; // ����ִ� list ����
	// list<int> lList(10); : 0���� �ʱ�ȭ�� �� 10���� ���� list ����
	// list<int> lList(3, 2); : 2�� �ʱ�ȭ �� �� 3���� ���� list ����
	// list<int> l2(l1); : l2�� l1�� �����ؼ� ����

	/*
	lList.assign(3, 4); : 4�� �ʱ�ȭ �� 3���� �����͸� �Ҵ�
	lList.front(); : �� ���� ������ ����
	lList.back(); : �� ���� ������ ����
	lList.begin(); == lList.rend(); : �� ���� ���Ҹ� ����Ŵ
	lList.end(); == lList.rbegin() : �� �� ���� ������ ����Ŵ

	lList.push_front(5); : �� �տ� 5�� ����
	lList.push_back(5); : �� �ڿ� 5�� ����
	lList.pop_front(); : �� �� ������ ����
	lList.pop_back(); : �� �� ������ ����
	lList.insert(iter, 2); : iter ��ġ�� 2 ����
	lList.erase(iter); : iter ��ġ�� �ִ� ������ ����
	lList.clear(); : ��ü ����

	lList.size(); : ������ ���� ��ȯ
	lList.remove(2); : 2�� ������ ��� ����
	lList.remove_if(Predicate); : ���� ������ Predicate�� �ش��ϴ� ������ ��� ����
	lList.reverse(); : ������
	lList.sort(); : ����
	l2.swap(l1); : l2�� l1�� �ٲ�
	l2.splice(iter2, l1); : l2���� iter2�� ����Ű�� ���� lt�� ��� �����͸� ������
	l2.splice(iter2, l1, iter1); : l2���� iter2�� ����Ű�� ���� l1�� iter1�� ����Ű�� �����͸� ����
	l2.splice(iter2, l1, iter1_1, iter1_2); : l2���� iter2�� ����Ű�� ���� l1�� iter1_1 �̻� iter1_2 �̸� ������ �����͸� ������
	lList.unique(); : ������ ���� �����Ͱ� ������ �ϳ��� ��ħ
	l2.merge(l1) : l1�� l2�� �պ� ������
	*/

	list<int>::iterator iter; // �ݺ���.
	iter = lList.begin();

	cout << "�տ� 1, �տ� 0, �ڿ� 2, �ڿ� 3, �ڿ� 55�� ����(0 1 2 3 55)" << endl;
	lList.push_front(1);
	lList.push_front(0);
	lList.push_back(2);
	lList.push_back(3);
	lList.push_back(55);
	for (iter = lList.begin(); iter != lList.end(); iter++)
		cout << *iter << ' ';
	cout << endl;
	
	cout << "�� �Ŀ� 2��° ��ġ�� �����Ϳ� �� ��, �� �ڸ� ������(2 3)" << endl;
	iter = lList.begin();
	lList.begin()++;
	lList.begin()++;
	lList.erase(iter);
	lList.pop_front();
	lList.pop_back();

	for (iter = lList.begin(); iter != lList.end(); iter++)
		cout << *iter << ' ';
	cout << endl << endl;

	cout << "����Ʈ �ʱ�ȭ �� ����Ʈ�� 1���� 20����, 7 3�� ����" << endl;
	lList.clear();
	for (int i = 1; i < 20; i++)
		lList.push_back(i);
	for (int i = 0; i < 3; i++)
		lList.push_back(7);
	for (iter = lList.begin(); iter != lList.end(); iter++)
		cout << *iter << ' ';
	cout << endl;

	cout << "7 ��ü ���� �� 4 ���� ����, 5��° ������ ����(10) �� 5��°�� 69 ����" << endl;
	lList.remove(7);
	lList.remove_if(P);

	iter = lList.begin();
	for (int i=0; i < 4; i++)
		iter++;
	lList.erase(iter);

	iter = lList.begin();
	for (int i = 0; i < 4; i++)
		iter++;
	lList.insert(iter, 69);

	for (iter = lList.begin(); iter != lList.end(); iter++)
		cout << *iter << ' ';
	cout << endl;

	return 0;
}