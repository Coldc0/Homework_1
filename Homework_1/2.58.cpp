#include "show_bytes.h"

//2.55-2.57
void test_show_bytes()
{
	int ival = 12345;
	float fval = (float)ival;
	int *pval = &ival;
	show_int(ival);
	show_float(fval);
	show_pointer(pval);

}
//2.58
int is_little_endian(void)
{
	int test = 0x00ABCDEF;
	byte_pointer p =(byte_pointer)&test;
	size_t len = sizeof(int);
	unsigned t = (unsigned)(test << 24);
	unsigned q = t >> 24;
	if (t== *p)
		return 0;
	else
		return 1;

}
//2.59
int  function_2_59(unsigned x, unsigned y)
{
	return ((x << 24) >> 24) + ((y >> 8) << 8);
}
//260
int  function_2_60(unsigned x, int i, unsigned char b)
{
	unsigned char *p = (unsigned char *)&x;
	unsigned left, right;//将数分为两部分
	int l = (3-i)*8+8, r = i*8+8;//向左移位，和向右移位
	left = (x >> r)<< r;
	right = (x << l)>>l;
	l == 32 ? right = 0: l = l;
	r == 32 ? left = 0: r = r;
	return left + right +( b << (i * 8));
}
int main()
{
	printf("%X\n", function_2_60(0x12345678,0,0xAB));
}
