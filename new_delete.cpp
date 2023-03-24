#include "new_delete.h"
#include "class_for_new_delete.h"

struct MyStructWithoutDestruction
{
	int x;
	double y;
};

struct MyStructWithDestruction
{
	int x;
	double y;
	~MyStructWithDestruction() {};
};

class MyClassWithoutDestruction
{
private:
	int x;
	double y;
public:
	MyClassWithoutDestruction() {};
};

class MyClassWithDestruction
{
private:
	int x;
	double y;
public:
	MyClassWithDestruction() { std::cout << "construct" << std::endl;  };
	~MyClassWithDestruction() { std::cout << "destruct" << std::endl; };
};

void test_new_delete_2()
{
	std::cout << std::endl << "built-in dt" << std::endl;
	
	auto p = new double[8];
	std::cout << _msize(p) << std::endl; // 8 * 8 = 64 bytes
	std::cout << *(size_t*)((char*)p - 8) << std::endl; // garbage value
	delete[] p;

	std::cout << std::endl << "Struct without explicit destruction" << std::endl;

	auto p21 = new MyStructWithoutDestruction[10];
	std::cout << _msize(p21) << std::endl; // 16 * 10 = 160 bytes
	//8 bytes to restore the number of elements in the array for 64-bit system
	//(presume) 4 bytes to restore that for 32-bit system
	std::cout << *(size_t*)((char*)p21 - 8) << std::endl; // garbage value
	delete[] p21;

	std::cout << std::endl << "Struct with explicit destruction" << std::endl;

	auto p22 = new MyStructWithDestruction[10];
	//std::cout << _msize(p22) << std::endl; // will cause runtime error
	//8 bytes to restore the number of elements in the array for 64-bit system
	//(presume) 4 bytes to restore that for 32-bit system
	std::cout << *(size_t*)((char*)p22 - 8) << std::endl; // should equal to 10.
	delete[] p22;

	std::cout << std::endl <<  "Class without explicit destruction" << std::endl;

	size_t num = 15;
	auto p31 = new MyClassWithoutDestruction[num];
	std::cout << _msize(p31) << std::endl; // 16 * num = 240 bytes
	//8 bytes to restore the number of elements in the array for 64-bit system
	//(presume) 4 bytes to restore that for 32-bit system
	std::cout << *(size_t*)((char*)p31 - 8) << std::endl; // garbage value
	delete[] p31;

	std::cout << std::endl << "Class with explicit destruction" << std::endl;

	num = 5;
	auto p32 = new MyClassWithDestruction[num];
	//std::cout << _msize(p32) << std::endl; // will cause runtime error
	//8 bytes to restore the number of elements in the array for 64-bit system
	//(presume) 4 bytes to restore that for 32-bit system
	auto ptr_to_len = (size_t*)((char*)p32 - 8);
	std::cout << *ptr_to_len << std::endl; // should equal to num.
	(*ptr_to_len)++;
	delete[] p32;

	return;
}

void test_new_delete()
{
	auto pi = new int;
	*pi = 16;
	delete pi;
	MyClass* pmc = new MyClass();
	delete pmc;

	auto pmcv = new MyClass[5];
	delete[] pmcv;
	pmcv = nullptr;
	int a = 10;
}
