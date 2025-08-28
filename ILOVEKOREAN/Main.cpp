#include <iostream>



int main()
{
	enum 열거형
	{
		가, 나, 다, 라, 마, 바, 사, 아, 자, 차, 카, 타, 파, 하
	};

	int 숫자 = 0;
	열거형 이넘 = 열거형::하;

	std::cout << 숫자 << '\t' << 이넘;

	return 0;
}
