#include <iostream>

int main()
{
	int amount = 1209875;
	double interestRate = 0.1965;
	double principalPlusInterest = 1 + interestRate;

	for (int i = 2; i <= 12; i++)
	{
		double monthlyPrincipal = double(amount / i);
		std::cout << i << "���� �Һ�)" << std::endl;
		std::cout << "����: " << monthlyPrincipal << "��" << std::endl;
		std::cout << "����: " << monthlyPrincipal * interestRate << "��" << std::endl;
		std::cout << "���� + ����: " << monthlyPrincipal * principalPlusInterest << "��" << std::endl;
		std::cout << "�� ����: " << monthlyPrincipal * interestRate * i << "��" << std::endl << std::endl;
	}

	return 0;
}