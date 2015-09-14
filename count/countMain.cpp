#include <algorithm>
#include <vector>
#include <iterator>
#include <iostream>
#include <functional>

using namespace std;


int main()
{
	int ia[] = { 0,1,2,3,4,5,6,6,6,7,8 };
	vector<int> iv( begin(ia), end(ia) );

	//数字6的个数
	cout << count(iv.begin(), iv.end(), 6); cout << endl;
	//3

	//小于7的个数
	cout << count_if(iv.begin(), iv.end(), bind2nd(less<int>(), 7)); cout << endl;
	//9

	//数字为4的位置，然后取其值（好无聊哦）
	cout << *find(iv.begin(), iv.end(), 4) << endl;
	//4

	//第一个比2大的数字的位置，然后取其值
	cout << *find_if(iv.begin(), iv.end(), bind2nd(greater<int>(), 2)) << endl;

	//找出iv之中子序列iv2所出现的最后一个位置（再往后3个位置的值）
	vector<int> iv2(ia+6, ia+8);
	cout << *(find_end(iv.begin(), iv.end(), iv2.begin(), iv2.end()) + 3); cout << endl;
	//8

	//找出iv之中子序列iv2所出现的第一个位置（再往后3个位置的值）
	cout << *(find_first_of(iv.begin(), iv.end(), iv2.begin(), iv2.end()) + 3); cout << endl;
	//7
	
	return 0;
}