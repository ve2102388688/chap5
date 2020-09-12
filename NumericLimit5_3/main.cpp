#include <iostream>
#include <limits>
#include <string>


int main()
{
	std::cout << std::boolalpha;

	// max of integral for bool
	std::cout << "max(short): " << std::numeric_limits<short>::max() << std::endl;
	std::cout << "max(int):   " << std::numeric_limits<int>::max() << std::endl;
	std::cout << "max(long): " << std::numeric_limits<long>::max() << std::endl;
	std::cout << std::endl;

	// max of floating-point
	std::cout << "max(float): " << std::numeric_limits<float>::max() << std::endl;
	std::cout << "max(double): " << std::numeric_limits<double>::max() << std::endl;
	std::cout << "max(long double): " << std::numeric_limits<long double>::max() << std::endl;
	std::cout << std::endl;

	// whether char is signed(正负数)
	std::cout << "is_signed(char): " << std::numeric_limits<char>::is_signed << std::endl;
	std::cout << std::endl;

	// is_specialized(数组极限值)
	std::cout << "is_specialized(std::string): " << std::numeric_limits<std::string>::is_specialized << std::endl;
	std::cout << std::endl;

}











