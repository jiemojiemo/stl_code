#include <numeric>
#include <iostream>
#include <vector>
#include <functional>
using namespace std;


int main()
{
	int ia[5] = { 1,2,3,4,5 };
	vector<int> iv(ia, ia + 5);
	int init = 10;
	//计算内积
	//   1  2  3  4  5
	//   *  *  *  *  *
	//   1	2  3  4  5
	// -----------------
// init+ 1+ 4+ 9+ 16+25 = 10+55 =65
	cout << inner_product(iv.begin(), iv.end(), iv.begin(), init) << endl;

	//   1  2  3  
	//   *  *  *  
	//   3	4  5 
	// -----------------
// init+ 3+ 8+ 15 = 10+26 =36
	cout << inner_product(iv.begin(), iv.begin() + 3, iv.begin() + 2, init) << endl;

	//利用仿函数代替operator* 和 operator+
	//   1  2  3  4  5
	//   +  +  +  +  +
	//   1	2  3  4  5
	// -----------------
// init- 1- 4- 9- 16-25 = -20
	cout << inner_product(iv.begin(), iv.end(), iv.begin(), 10, minus<int>(), plus<int>()) << endl;



	return 0;
}