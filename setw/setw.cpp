#include <iostream>
#include <iomanip>

enum MyEnum
{
	mon,
	tue,
	wed=10,
	tur
};

union MyUnion
{
	char c;
	int i;
	double d;
};

struct MyStruct
{
	char c;
	int i;
	double d;
};

int main()
{
	MyEnum e = MyEnum::mon;

	switch (e)
	{
	case 0:
		std::cout << "Mon";
		break;
	case 1:
		std::cout << "Tue";
		break;
	case 2:
		std::cout << "Wed";
		break;
	case 3:
		std::cout << "Tur";
		break;
	//case mon:
	//	std::cout << "Mon";
	//	break;
	//case tue:
	//	std::cout << "Tue";
	//	break;
	//case wed:
	//	std::cout << "Wed";
	//	break;
	//case tur:
	//	std::cout << "Tur";
	//	break;
	default:
		break;
	}

	return 0;
}