/*
... iss Crew
... Made By Mukho
... 2020-07-29 WED
... Get Process Name I Want
*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <TlHelp32.h>
#include <wchar.h>
using namespace std;

#define FIND_PROCESS_NAME L"chrome.exe" // ã�� ���μ��� �̸� ����

void PrintProcessList();

int main()
{
	PrintProcessList();
	return 0;
}

void PrintProcessList()
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
			if (!wcscmp(ProcessEntry32.szExeFile, findProcessName) && IsWindowVisible) // ���� process name�� ã�� process name�� ������
			{
				printf("%ls [%d]\n", ProcessEntry32.szExeFile, ProcessEntry32.th32ProcessID); // ��� ( Process PID )
			}
			bProcessFound = Process32Next(hSnapshot, &ProcessEntry32); // Get next process
		}
		CloseHandle(hSnapshot); // Close snapshot handle
	}
}