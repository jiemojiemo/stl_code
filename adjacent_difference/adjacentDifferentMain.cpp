#include <numeric>
#include <vector>
#include <iostream>
#include <iterator>
using namespace std;

int main()
{
	int ia[5] = { 1,2,3,4,5 };
	vector<int> iv(ia, ia + 5);

	//作为输出
	ostream_iterator<int> oiter(cout, " ");

	//输出iv元素间的差值
	adjacent_difference(iv.begin(), iv.end(), oiter);	//1 1 1 1 1
	cout << endl;

	//输出iv元素之间的两两相加的值
	adjacent_difference(iv.begin(), iv.end(), oiter, [](int a, int b) {
		return a + b;
	});
	cout << endl;

}