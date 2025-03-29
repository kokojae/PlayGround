#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <locale>
#include <codecvt>
#include <vector>

int main() {
    // �Է� ���� "List.txt"�� wide ���� ��Ʈ������ ���� (UTF-8 ���ڵ�)
    std::wifstream wif("List.txt");
    wif.imbue(std::locale(std::locale(), new std::codecvt_utf8<wchar_t>));
    if (!wif) {
        std::wcerr << L"List.txt ������ �� �� �����ϴ�." << std::endl;
        return 1;
    }

    // �̸��� ������ ������ ����
    std::vector<std::wstring> names;
    std::vector<std::wstring> counts;

    std::wstring line;
    while (std::getline(wif, line)) {
        // �� ���� �ǳʶݴϴ�.
        if (line.empty())
            continue;

        // �� ���� ������ "�Ϻ��� ~ ���� X��" �Դϴ�.
        // ������ ������ �������� �̸��� ���� �κ��� �и��մϴ�.
        size_t pos = line.rfind(L' ');
        if (pos == std::wstring::npos)
            continue;

        // �̸�: ���� �������� ���ڿ�
        std::wstring name = line.substr(0, pos);

        // ���� �κ�: ���� ���ĺ��� ������, �ڿ� ���� "��"�� ����
        std::wstring countPart = line.substr(pos + 1);
        if (!countPart.empty() && countPart.back() == L'��') {
            countPart.pop_back();
        }

        names.push_back(name);
        counts.push_back(countPart);
    }
    wif.close();

    // �̸��� ���� ������ ������ �޸��� ���е� ���ڿ��� ��ȯ
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

    // "Name.txt" ���Ͽ� �̸� ��� (UTF-8 ���ڵ�)
    std::wofstream wofName("Name.txt");
    wofName.imbue(std::locale(std::locale(), new std::codecvt_utf8<wchar_t>));
    if (!wofName) {
        std::wcerr << L"Name.txt ������ �� �� �����ϴ�." << std::endl;
        return 1;
    }
    wofName << nameOutput;
    wofName.close();

    // "Count.txt" ���Ͽ� ���� ��� (UTF-8 ���ڵ�)
    std::wofstream wofCount("Count.txt");
    wofCount.imbue(std::locale(std::locale(), new std::codecvt_utf8<wchar_t>));
    if (!wofCount) {
        std::wcerr << L"Count.txt ������ �� �� �����ϴ�." << std::endl;
        return 1;
    }
    wofCount << countOutput;
    wofCount.close();

    std::wcout << L"������ ���������� ����Ǿ����ϴ�." << std::endl;
    return 0;
}
