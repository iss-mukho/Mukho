#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "SortedArrayList.h"
using namespace std;

class Application
{
private:
	int cmd;

	ifstream InFile;
	ofstream OutFile;
	SortedArrayList sList;
public:
	Application();
	~Application();

	void Run();
	int GetCommand();

	void InsertUser();
	void DeleteUser();
	void UpdateUser();
	void SearchById();
	void SearchByName();
	void PrintAllUser();

	int OpenInFile(string fileName);
	int OpenOutFile(string fileName);

	int ReadDataFromFile();
	int WriteDataFromFile();

	void SearchInListById(UserType& user);
	void SearchInListByName(UserType& user);
};