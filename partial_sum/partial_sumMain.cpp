#include <numeric>
#include <functional>
#include <vector>
#include <iterator>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int ia[5] = { 1,2,3,4,5 };
	vector<int> iv(ia, ia + 5);			

	//作为输出
	ostream_iterator<int> oiter(cout, " ");

	//计算局部总和
	partial_sum(begin(iv), end(iv), oiter); 
	//1 3 6 10 15 ( 第n个新元素是前n个旧元素的相加总计 )

	cout << endl;
	//计算局部阶乘
	partial_sum(begin(iv), end(iv), oiter,[](int a, int b) 
	{
		return a*b;
	});
	// 1 2 6 24 120
	cout << endl;

	//计算斐波那契数列
	vector<int> fac = {1,1};
	int loop = 20;
	cout << fac[0] << endl;
	while (loop-- > 0)
	{
		partial_sum(begin(fac), end(fac), begin(fac), [&](int a, int b)
		{
			swap( fac[0], fac[1] );
			return a+b;
		});
		cout <<  fac[0] << endl;
	}
	//fac:  1  1
	//fac:  1  2    swap->  2 1
	//fac:  2  3    swap->  3 2
	//fac:  3  5    swap->  5 3
	//fac:  5  8    swap->  8 5
	//fac:  8  13   swap->  13 8
	//fac:  ......
	return 0;
}