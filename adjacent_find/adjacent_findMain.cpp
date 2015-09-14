#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int ia[] = { 0,1,2,3,4,5,6,6,6,7,2,8,3 };
	vector<int> iv( begin(ia), end(ia) );

	//�ҳ�iv֮������Ԫ����ȵĵ�һ��Ԫ��
	cout << *adjacent_find(iv.begin(), iv.end()) << endl;
	//6

	//�ҳ�iv֮������Ԫ���У�ǰһ��Ԫ�ش��ں�һ��Ԫ�ص�ǰһ��Ԫ�ص�ֵ
	cout << *adjacent_find(iv.begin(), iv.end(), [](int a, int b)
	{
		return a > b;
	}); cout << endl;
	//7

	//�ҳ�iv֮������Ԫ������������ż���ĵ�һ��Ԫ��
	cout << *adjacent_find(iv.begin(), iv.end(), [](int a, int b)
	{
		return (a % 2 == 0) && (b % 2 == 0);
	});
	//6

	
	return 0;
}