#include <algorithm>
#include <vector>
#include <iostream>
#include <functional>

using namespace std;

template <typename T>
void display(const T& x)
{
	cout << x << " ";
}
int main()
{
	///////////////////////////////remove///////////////////////////////////////////
	{
		int ia[] = { 0,1,2,3,4,5,6,6,6,7,8 };
		vector<int> iv(begin(ia), end(ia));

		//移除（但不删除）元素6，尾端可能有残余数据（可以erase函数除去）
		remove(iv.begin(), iv.end(), 6);
		for_each(iv.begin(), iv.end(), display<int>); cout << endl;
		//0 1 2 3 4 5 7 8 6 7 8
	}

	///////////////////////////////remove_copy///////////////////////////////////////////
	{
		int ia[] = { 0,1,2,3,4,5,6,6,6,7,8 };
		vector<int> iv(begin(ia), end(ia));
		//移除（但不删除）元素6，结果置于另一个区间
		vector<int> iv2(12);
		remove_copy(iv.begin(), iv.end(), iv2.begin(), 6);
		for_each(iv2.begin(), iv2.end(), display<int>); cout << endl;
		//0 1 2 3 4 5 7 8 (0 0 0 0)
	}
	///////////////////////////////remove_if///////////////////////////////////////////
	{
		int ia[] = { 0,1,2,3,4,5,6,6,6,7,8 };
		vector<int> iv(begin(ia), end(ia));

		//移除（但不删除）小于6的元素，尾端可能有残余数据
		remove_if(iv.begin(), iv.end(), bind2nd(less<int>(), 6)); 
		for_each(iv.begin(), iv.end(), display<int>); cout << endl;
		//6 6 6 7 8 5 6 6 6 7 8
	}
	///////////////////////////////remove_copy_if///////////////////////////////////////////
	{
		int ia[] = { 0,1,2,3,4,5,6,6,6,7,8 };
		vector<int> iv(begin(ia), end(ia));

		//移除（但不删除）小于7的元素，结果置于另一个区间
		vector<int> iv2(12);
		remove_copy_if(iv.begin(), iv.end(), iv2.begin(), bind2nd(less<int>(), 7));
		for_each(iv2.begin(), iv2.end(), display<int>); cout << endl;
		//7 8 0 0 0 0 0 0 0 0 0 0
	}


	return 0;
}
