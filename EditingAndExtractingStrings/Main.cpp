#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <locale>
#include <codecvt>
#include <vector>

int main() {
    // 입력 파일 "List.txt"를 wide 문자 스트림으로 열기 (UTF-8 인코딩)
    std::wifstream wif("List.txt");
    wif.imbue(std::locale(std::locale(), new std::codecvt_utf8<wchar_t>));
    if (!wif) {
        std::wcerr << L"List.txt 파일을 열 수 없습니다." << std::endl;
        return 1;
    }

    // 이름과 수량을 저장할 벡터
    std::vector<std::wstring> names;
    std::vector<std::wstring> counts;

    std::wstring line;
    while (std::getline(wif, line)) {
        // 빈 줄은 건너뜁니다.
        if (line.empty())
            continue;

        // 각 줄의 형식은 "완벽한 ~ 가죽 X장" 입니다.
        // 마지막 공백을 기준으로 이름과 수량 부분을 분리합니다.
        size_t pos = line.rfind(L' ');
        if (pos == std::wstring::npos)
            continue;

        // 이름: 공백 전까지의 문자열
        std::wstring name = line.substr(0, pos);

        // 수량 부분: 공백 이후부터 끝까지, 뒤에 붙은 "장"을 제거
        std::wstring countPart = line.substr(pos + 1);
        if (!countPart.empty() && countPart.back() == L'장') {
            countPart.pop_back();
        }

        names.push_back(name);
        counts.push_back(countPart);
    }
    wif.close();

    // 이름과 수량 벡터의 내용을 콤마로 구분된 문자열로 변환
    std::wstring nameOutput;
    std::wstring countOutput;
    for (size_t i = 0; i < names.size(); i++) {
        nameOutput += names[i];
        countOutput += counts[i];
        if (i != names.size() - 1) {
            nameOutput += L",";
            countOutput += L",";
        }
    }

    // "Name.txt" 파일에 이름 출력 (UTF-8 인코딩)
    std::wofstream wofName("Name.txt");
    wofName.imbue(std::locale(std::locale(), new std::codecvt_utf8<wchar_t>));
    if (!wofName) {
        std::wcerr << L"Name.txt 파일을 열 수 없습니다." << std::endl;
        return 1;
    }
    wofName << nameOutput;
    wofName.close();

    // "Count.txt" 파일에 수량 출력 (UTF-8 인코딩)
    std::wofstream wofCount("Count.txt");
    wofCount.imbue(std::locale(std::locale(), new std::codecvt_utf8<wchar_t>));
    if (!wofCount) {
        std::wcerr << L"Count.txt 파일을 열 수 없습니다." << std::endl;
        return 1;
    }
    wofCount << countOutput;
    wofCount.close();

    std::wcout << L"파일이 성공적으로 저장되었습니다." << std::endl;
    return 0;
}
