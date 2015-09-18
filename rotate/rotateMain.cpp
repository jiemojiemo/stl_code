#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;

template <typename T>
void display(const T& x)
{
	cout << x << " ";
}
//循环位移字符串
//n > 0 向右平移
//n < 0 向左平移
void charShift( char* str,int n );

int main()
{
	int ia[] = { 0,1,2,3,4,5,6,7,8,9 };
	vector<int> iv(begin(ia), end(ia));

	auto middle = iv.end() - 2;		//*middle = 8
	//旋转（互换元素）[first, middle) 和 [middle, last)
	rotate(iv.begin(), middle, iv.end());
	for_each(iv.begin(), iv.end(), display<int>); cout << endl;
	//8 9 0 1 2 3 4 5 6 7

	vector<int> iv3(12);
	middle = iv.begin() + 4;	//*middle = 4
	//旋转（互换元素）[first, middle) 和 [middle, last),结果置于另一个区间
	rotate_copy(iv.begin(), middle, iv.end(), iv3.begin());
	for_each(iv3.begin(), iv3.end(), display<int>); cout << endl;
	//2 3 4 5 6 7 8 9 0 1 (0)

	vector<int> iv2 = { 0,1,2,3 };
	middle = iv2.begin() + 2;
	rotate(iv2.begin(), middle, iv2.end());
	for_each(iv2.begin(), iv2.end(), display<int>); cout << endl;


	//面试中碰见的一道题
	//循环位移一个字符串。
	//n>0 向右移动n位
	//n<0 向左移动n位
	char str[] = "abcdefg";
	charShift( str, -2 );
	cout << str << endl;

	return 0;
}

void charShift(char* str, int n)
{
	assert(str != nullptr);

	int strLength = strlen(str);
	n %= strLength;
	if (0 == n)
		return;

	string tmp(str);
	auto middle = tmp.begin();

	if (n > 0)
		middle = middle + strLength - n;//tmp.end() - n
	else
		middle += (-n);//tmp.begin() + abs(n)
	//进行旋转
	rotate( tmp.begin(), middle, tmp.end() );
	//将结果复制到原来的字符串中
	copy( tmp.begin(), tmp.end(), str );
}