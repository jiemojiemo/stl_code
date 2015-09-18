#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	{
		int ia[] = { 10,1,2,3,4,5,6 };
		vector<int> iv(begin(ia), end(ia));
		vector<int> iv2(ia + 2, ia + 4);
		vector<int> iv3 = { 4,6,8 };

		//查找某个子序列第一次出现的地方
		cout << *search(iv.begin(), iv.end(), iv2.begin(), iv2.end()) << endl;
		//2

		//查找某个子序列第一次符合条件的地方
		cout << *search(iv.begin(), iv.end(), iv3.begin(), iv3.end(), [](int x, int y)
		{
			return y%x == 0;
		}); cout << endl;
		//2
		cout << endl;

	}

	{
		int ia[] = { 0,1,2,3,4,5,5,5,6 };
		vector<int> iv( begin(ia), end(ia) );

		//查找连续出现2个5的子序列起始点
		cout << *search_n(iv.begin(), iv.end(), 2, 5); cout << endl;
		//5

		//查找连续出现3个6的公因子的子序列的起始点
		cout << *search_n(iv.begin(), iv.end(), 3, 6, [](int x, int y)
		{
			if (0 == x)
				return false;
			return y%x == 0;
		}); cout << endl;
		//1


		cout << endl;
	}
	
	return 0;
}