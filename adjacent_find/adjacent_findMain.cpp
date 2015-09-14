#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int ia[] = { 0,1,2,3,4,5,6,6,6,7,2,8,3 };
	vector<int> iv( begin(ia), end(ia) );

	//找出iv之中相邻元素相等的第一个元素
	cout << *adjacent_find(iv.begin(), iv.end()) << endl;
	//6

	//找出iv之中相邻元素中，前一个元素大于后一个元素的前一个元素的值
	cout << *adjacent_find(iv.begin(), iv.end(), [](int a, int b)
	{
		return a > b;
	}); cout << endl;
	//7

	//找出iv之中相邻元素中两个都是偶数的第一个元素
	cout << *adjacent_find(iv.begin(), iv.end(), [](int a, int b)
	{
		return (a % 2 == 0) && (b % 2 == 0);
	});
	//6

	
	return 0;
}