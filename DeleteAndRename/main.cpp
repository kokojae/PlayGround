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

	// Ÿ�� Ž���� ���� ��ó��
	path += "\\*.*";

	// ù ���� Ž�� �� ���� ���� Ȯ��
	if ((handle = _findfirst(path.c_str(), &fd)) == -1L) {
		cout << "No file in directory!" << endl;
		return 0;
	}

	// ���� Ž�� ���� ����
	do {
		string temp = fd.name;
		if (temp.find(keyword) == string::npos) {
			// ���ϸ� keyword ������

		}
		else {
			// ���ϸ� keyword ����
		}
	} while (_findnext(handle, &fd) == 0);
	// ���� ����
	_findclose(handle);

	return 0;
}
