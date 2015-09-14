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

	//����6�ĸ���
	cout << count(iv.begin(), iv.end(), 6); cout << endl;
	//3

	//С��7�ĸ���
	cout << count_if(iv.begin(), iv.end(), bind2nd(less<int>(), 7)); cout << endl;
	//9

	//����Ϊ4��λ�ã�Ȼ��ȡ��ֵ��������Ŷ��
	cout << *find(iv.begin(), iv.end(), 4) << endl;
	//4

	//��һ����2������ֵ�λ�ã�Ȼ��ȡ��ֵ
	cout << *find_if(iv.begin(), iv.end(), bind2nd(greater<int>(), 2)) << endl;

	//�ҳ�iv֮��������iv2�����ֵ����һ��λ�ã�������3��λ�õ�ֵ��
	vector<int> iv2(ia+6, ia+8);
	cout << *(find_end(iv.begin(), iv.end(), iv2.begin(), iv2.end()) + 3); cout << endl;
	//8

	//�ҳ�iv֮��������iv2�����ֵĵ�һ��λ�ã�������3��λ�õ�ֵ��
	cout << *(find_first_of(iv.begin(), iv.end(), iv2.begin(), iv2.end()) + 3); cout << endl;
	//7
	
	return 0;
}