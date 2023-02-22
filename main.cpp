#pragma once
#include <iostream>
#include "std_chrono.h"

void func(int x)
{
	std::cout << "***" << std::endl;
}

void func_inline(int x) inline
{
	std::cout << "***" << std::endl;
}

template <class T_>
void func_template(int x)
{
	std::cout << "***" << std::endl;
}

template <class T_> inline
void func_template_inline(int x)
{
	std::cout << "***" << std::endl;
}

int main()
{
	
	return 0;
}