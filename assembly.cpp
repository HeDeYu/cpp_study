#include "assembly.h"

void test_assembly()
{
	int x = 20;
	char c = 'a';
	bool b = true;
	wchar_t wc = 'a';

	float f = 0;
	double d = 20;

	short s = 1;
	long l = 1;
	long long ll = 1;

	int* pi = nullptr;
	float* pf = nullptr;
	char* pc = nullptr;

	pi = &x;
	pc = &c;
	pf = &f;

	int a[5] = {1, 2, 3, 4, 5};
	int aa[5] = { 1, 2, 3};

	auto pin = new int[6];
}
