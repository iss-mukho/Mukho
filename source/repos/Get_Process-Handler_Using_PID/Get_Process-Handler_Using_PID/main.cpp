/*
... iss Crew
... Made By Mukho
... 2020-07-29 WED
... Get Process-Handler using PID
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <TlHelp32.h>
#include <wchar.h>
#include <vector>
using namespace std;

#define FIND_PROCESS_NAME L"Hwp.exe" // ã�� ���μ��� �̸� ����

vector<DWORD> pidList; // ���μ����� ������ ����
vector<HWND> hdrList; // ���μ��� �ڵ鷯�� ������ ����

void SetProcessList(); // ���μ��� ����� ���Ϳ� ����

ULONG ProcIDFromWnd(HWND hwnd) // ������ �ڵ�� ���μ��� ���̵� ���   
{
	ULONG idProc;
	GetWindowThreadProcessId(hwnd, &idProc);
	return idProc;
}

HWND GetWinHandle(ULONG pid) // ���μ��� ���̵�� ������ �ڵ� ���   
{
	HWND tempHwnd = FindWindow(NULL, NULL); // �ֻ��� ������ �ڵ� ã��   

	while (tempHwnd != NULL)
	{
		// �ֻ��� �ڵ����� üũ, ��ư � �ڵ��� ���� �� �����Ƿ� �����ϱ� ����
		if (GetParent(tempHwnd) == NULL)
			if (pid == ProcIDFromWnd(tempHwnd))
				return tempHwnd;
		tempHwnd = GetWindow(tempHwnd, GW_HWNDNEXT); // ���� ������ �ڵ� ã��   
	}
	return NULL;
}

void SetProcessList()
{
	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0); // CreateToolhelp32Snapshot()���� snapshot handle�� ����(TH32CS_SNAPPROCESS = process list)

	if (hSnapshot) // snapshot handle�� null�� �ƴϸ�
	{
		const WCHAR* findProcessName = FIND_PROCESS_NAME; // �� ������ ã�� process name ����

		PROCESSENTRY32 ProcessEntry32; // Snap all process
		ProcessEntry32.dwSize = sizeof(PROCESSENTRY32);
		BOOL bProcessFound;
		bProcessFound = Process32First(hSnapshot, &ProcessEntry32); // Get first process(True or False)

		while (bProcessFound) // ù process�� �����ϸ�
		{
			if (!wcscmp(ProcessEntry32.szExeFile, findProcessName)) // ���� process name�� ã�� process name�� ������
			{
				pidList.push_back(ProcessEntry32.th32ProcessID); // ���� (Process ID)
			}
			bProcessFound = Process32Next(hSnapshot, &ProcessEntry32); // Get next process
		}
		CloseHandle(hSnapshot); // Close snapshot handle
	}
}

int main()
{
	SetProcessList();

	// ���μ��� ����Ʈ, �ڵ鷯 ����Ʈ ����
	for (unsigned int i = 0; i < pidList.size(); i++)
	{
		hdrList.push_back(GetWinHandle(pidList[i]));
		cout << pidList[i] << " // " << hdrList[i] << endl; // Ȯ�ο� ���
	}

	return 0;
}