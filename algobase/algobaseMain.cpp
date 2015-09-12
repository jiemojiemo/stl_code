#include <algorithm>
#include <vector>
#include <iostream>
#include <functional>
#include <iterator>
#include <string>

using namespace std;

template <typename T>
void display(const T& x)
{
	cout << x << " " << endl;
}

template <typename T>
bool cmp(const T& x, const T& y)
{
	return x < y;
}

template <typename T>
struct Cmp {
	bool operator()(const T& x, const T& y) { return x < y; }
};
int main()
{
	int ia[9] = { 0,1,2,3,4,5,6,7,8 };
	vector<int> iv1(ia, ia+5);
	vector<int> iv2(ia, ia+9);

	cout << "--------------------------mismatch----------------------" << endl;
	//找到第一个不匹配的元素
	auto mis = mismatch(iv1.begin(), iv1.end(), iv2.begin());
	//获得一个pair, 其中first指向第一个迭代器的不匹配点， second指向第二个迭代器的不匹配点
	//首先要进行判断是否不等于荣区的end()，才能用于输出
	if (mis.first != iv1.end())
		cout << *mis.first << " ";
	if (mis.second != iv2.end())
		cout << *mis.second << endl;


	cout << "--------------------------equal----------------------" << endl;
	//如果两个序列在[first,last)区间内相等，返回true，否则返回false
	//如果第二序列的元素比较多，多出来的元素不考虑
	cout << equal(iv1.begin(), iv1.end(), iv2.begin()) << endl;

	//自定义比较函数
	cout << equal(iv1.begin(), iv1.end(), &iv2[3], [](int x, int y)
	{
		return x < y;
	}) << endl;


	cout << "--------------------------fill----------------------" << endl;
	//区间内全部填100
	fill( iv1.begin(), iv1.end(), 100 );
	for_each( iv1.begin(), iv1.end(), display<int> );
	//从指定位置开始填数字
	fill_n(iv1.begin(), 2, 99);
	for_each(iv1.begin(), iv1.end(), display<int>);


	cout << "--------------------------iter_swap----------------------" << endl;
	auto iter1 = iv1.begin();	//指向99
	auto iter2 = iter1;		
	advance( iter2, 3 );		//指向100
	iter_swap( iter1, iter2 );
	cout << *iter1 << " " << *iter2 << endl;
	for_each(iv1.begin(), iv1.end(), display<int>);

	cout << "--------------------------lexicographical_compare----------------------" << endl;
	string stra1[] = {"Jamie", "JJHou", "Jason"};
	string stra2[] = {"Jamie", "JJhou", "Jerry"};
	//以 字典序 对两个序列进行比较
	cout << lexicographical_compare(stra1, stra1 + 2, stra2, stra2 + 2) << endl;

	cout << lexicographical_compare(stra1, stra1 + 2, stra2, stra2 + 2, greater<string>()) << endl;
	return 0;
}