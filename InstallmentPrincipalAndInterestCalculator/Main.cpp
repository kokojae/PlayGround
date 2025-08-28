#include <iostream>

int main()
{
	int amount = 1209875;
	double interestRate = 0.1965;
	double principalPlusInterest = 1 + interestRate;

	for (int i = 2; i <= 12; i++)
	{
		double monthlyPrincipal = double(amount / i);
		std::cout << i << "개월 할부)" << std::endl;
		std::cout << "원금: " << monthlyPrincipal << "원" << std::endl;
		std::cout << "이자: " << monthlyPrincipal * interestRate << "원" << std::endl;
		std::cout << "원금 + 이자: " << monthlyPrincipal * principalPlusInterest << "원" << std::endl;
		std::cout << "총 이자: " << monthlyPrincipal * interestRate * i << "원" << std::endl << std::endl;
	}

	return 0;
}