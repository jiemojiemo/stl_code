//请使用比较完整支持c++11特性的编译器进行编译
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int main()
{
	int ia[5] = { 1,2,3,4,5 };
	vector<int> iv(ia, ia + 5);
	//计算总和
	cout << accumulate(iv.begin(), iv.end(), 0) << endl;
	//计算2倍总和
	cout << accumulate(iv.begin(), iv.end(), 0, [](int init, int b) {return init + 2 * b; }) << endl;
	//计算偶数的总和
	cout << accumulate(iv.begin(), iv.end(), 0, [](int init, int b)
	{
		if (b % 2 == 0)
			return init + b;
		return init;
	}) << endl;
	//计算相乘，注意init的值需要为1
	cout << accumulate(iv.begin(), iv.end(), 1, [](int init, int b)
	{
		return init * b;
	}) << endl;

	//计算方差
	double ave = accumulate(iv.begin(), iv.end(), 0.0) / iv.size();
	auto variance = accumulate(iv.begin(), iv.end(), 0.0, [&](double init, int b)
	{
		return init + (b - ave)*(b - ave);
	});
	variance /= iv.size();
	cout << variance << endl;
}