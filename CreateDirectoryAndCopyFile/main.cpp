#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
	string sourcePath = "";
	string targetPath = "";

	// ���� ����
	while (true)
	{
		cout << "Enter Q to quit." << endl;
		cout << "Input source path: ";
		cin >> sourcePath;
		if ((sourcePath == "Q") || (sourcePath == "q")) break;
	}

	return 0;
}
