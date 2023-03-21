#include "std_ratio.h"

void test_ratio()
{
	std::ratio<10, 100> a;
	std::cout << a.num << std::endl; // 1
	std::cout << a.den << std::endl; // 10
	typedef std::ratio<10, 100> one_tenth;
	std::cout << one_tenth::num << "/" << one_tenth::den << std::endl; // 1/10

	typedef std::ratio<2, 5> two_fifths;
	typedef std::ratio_add<one_tenth, two_fifths> add_res;
	std::cout << add_res::num << "/" << add_res::den << std::endl; // 1/2
}