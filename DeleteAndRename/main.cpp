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

	// 첫 파일 탐색 및 파일 유무 확인
	if ((handle = _findfirst((path + "\\*.*").c_str(), &fd)) == -1L) {
		cout << "No file in directory!" << endl;
		return 0;
	}

	// 파일 탐색 메인 루프
	do {
		// 파일이 디렉토리파일인지 확인
		if (fd.attrib & _A_SUBDIR)
			continue;// 디렉토리라면 별도의 처리 없이 넘어감

		// 파일명에 keyword 미존재 시
		if (string(fd.name).find(keyword) == string::npos) {
			// 파일 경로 생성
			string filePath = path + "\\" + fd.name;
			// 파일 삭제
			int nResult = remove(filePath.c_str());
			// 삭제 성공 시
			if (nResult == 0)
				cout << "Complated remove file: " << filePath << endl;
			// 삭제 실패 시
			else if (nResult == -1)
				cout << "Failed remove file: " << filePath << endl;
		}
		// 파일명에 keyword 존재
		else {
			// 파일 기존 경로
			string filePath = path + "\\" + fd.name;
			// 변경할 파일명
			string change = fd.name;
			// 키워드 삭제
			for (char c : keyword)
				change.erase(remove(change.begin(), change.end(), c), change.end());
			// 파일 변경할 경로
			string renamePath = path + "\\" + change;

			// 파일명 변경에 실패했다면
			if (rename(filePath.c_str(), renamePath.c_str()) != 0)
				cout << "Failed rename file: " << filePath << endl;
			// 파일명 변경에 성공했다면
			else
				cout << "Complated rename file: " << filePath << endl;
		}
	} while (_findnext(handle, &fd) == 0);
	// 연결 해제
	_findclose(handle);

	return 0;
}
