#include <stdio.h>
#include <iostream>
#include <io.h>
#include <string>

using namespace std;

int main()
{
	// 변수 선언
	string path;			// 경로
	string keyword;			// 처리의 기준이 될 문자열
	struct _finddata_t fd;	// 파일 탐색에 필요한 구조체
	intptr_t handle;		// 핸들

	// 변수값 입력
	cout << "path: ";
	cin >> path;
	cout << "keyword: ";
	cin >> keyword;

	// 타일 탐색을 위한 후처리
	path += "\\*.*";

	// 첫 파일 탐색 및 파일 유무 확인
	if ((handle = _findfirst(path.c_str(), &fd)) == -1L) {
		cout << "No file in directory!" << endl;
		return 0;
	}

	// 파일 탐색 메인 루프
	do {
		// 파일이 디렉토리파일인지 확인
		if (fd.attrib & _A_SUBDIR)
			continue;// 디렉토리라면 별도의 처리 없이 넘어감

		string temp = fd.name;
		if (temp.find(keyword) == string::npos) {
			// 파일명에 keyword 미존재

		}
		else {
			// 파일명에 keyword 존재

		}
	} while (_findnext(handle, &fd) == 0);
	// 연결 해제
	_findclose(handle);

	return 0;
}
