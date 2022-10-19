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

		// ���ϸ� keyword ������ ��
		if (string(fd.name).find(keyword) == string::npos) {
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
			// ���� ���� ���
			string filePath = path + "\\" + fd.name;
			// ������ ���ϸ�
			string change = fd.name;
			// Ű���� ����
			for (char c : keyword)
				change.erase(remove(change.begin(), change.end(), c), change.end());
			// ���� ������ ���
			string renamePath = path + "\\" + change;

			// ���ϸ� ���濡 �����ߴٸ�
			if (rename(filePath.c_str(), renamePath.c_str()) != 0)
				cout << "Failed rename file: " << filePath << endl;
			// ���ϸ� ���濡 �����ߴٸ�
			else
				cout << "Complated rename file: " << filePath << endl;
		}
	} while (_findnext(handle, &fd) == 0);
	// ���� ����
	_findclose(handle);

	return 0;
}
