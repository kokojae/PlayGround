#include <stdio.h>
#include <iostream>
#include <io.h>
#include <string>

using namespace std;

int main()
{
	// ���� ����
	string path;			// ���
	string keyword;			// ó���� ������ �� ���ڿ�
	struct _finddata_t fd;	// ���� Ž���� �ʿ��� ����ü
	intptr_t handle;		// �ڵ�

	// ������ �Է�
	cout << "path: ";
	cin >> path;
	cout << "keyword: ";
	cin >> keyword;

	// ù ���� Ž�� �� ���� ���� Ȯ��
	if ((handle = _findfirst((path + "\\*.*").c_str(), &fd)) == -1L) {
		cout << "No file in directory!" << endl;
		return 0;
	}

	// ���� Ž�� ���� ����
	do {
		// ������ ���丮�������� Ȯ��
		if (fd.attrib & _A_SUBDIR)
			continue;// ���丮��� ������ ó�� ���� �Ѿ

		string temp = fd.name;
		// ���ϸ� keyword ������ ��
		if (temp.find(keyword) == string::npos) {
			// ���� ��� ����
			string filePath = path + "\\" + fd.name;
			// ���� ����
			int nResult = remove(filePath.c_str());
			// ���� ���� ��
			if (nResult == 0)
				cout << "Complated remove file: " << filePath << endl;
			// ���� ���� ��
			else if (nResult == -1)
				cout << "Failed remove file: " << filePath << endl;
		}
		// ���ϸ� keyword ����
		else {
			
		}
	} while (_findnext(handle, &fd) == 0);
	// ���� ����
	_findclose(handle);

	return 0;
}
