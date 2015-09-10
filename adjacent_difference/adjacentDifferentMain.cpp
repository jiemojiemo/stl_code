#include <numeric>
#include <vector>
#include <iostream>
#include <iterator>
using namespace std;

int main()
{
	int ia[5] = { 1,2,3,4,5 };
	vector<int> iv(ia, ia + 5);

	//��Ϊ���
	ostream_iterator<int> oiter(cout, " ");

	//���ivԪ�ؼ�Ĳ�ֵ
	adjacent_difference(iv.begin(), iv.end(), oiter);	//1 1 1 1 1
	cout << endl;

	//���ivԪ��֮���������ӵ�ֵ
	adjacent_difference(iv.begin(), iv.end(), oiter, [](int a, int b) {
		return a + b;
	});
	cout << endl;

}