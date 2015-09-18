#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;

template <typename T>
void display(const T& x)
{
	cout << x << " ";
}
//ѭ��λ���ַ���
//n > 0 ����ƽ��
//n < 0 ����ƽ��
void charShift( char* str,int n );

int main()
{
	int ia[] = { 0,1,2,3,4,5,6,7,8,9 };
	vector<int> iv(begin(ia), end(ia));

	auto middle = iv.end() - 2;		//*middle = 8
	//��ת������Ԫ�أ�[first, middle) �� [middle, last)
	rotate(iv.begin(), middle, iv.end());
	for_each(iv.begin(), iv.end(), display<int>); cout << endl;
	//8 9 0 1 2 3 4 5 6 7

	vector<int> iv3(12);
	middle = iv.begin() + 4;	//*middle = 4
	//��ת������Ԫ�أ�[first, middle) �� [middle, last),���������һ������
	rotate_copy(iv.begin(), middle, iv.end(), iv3.begin());
	for_each(iv3.begin(), iv3.end(), display<int>); cout << endl;
	//2 3 4 5 6 7 8 9 0 1 (0)

	vector<int> iv2 = { 0,1,2,3 };
	middle = iv2.begin() + 2;
	rotate(iv2.begin(), middle, iv2.end());
	for_each(iv2.begin(), iv2.end(), display<int>); cout << endl;


	//������������һ����
	//ѭ��λ��һ���ַ�����
	//n>0 �����ƶ�nλ
	//n<0 �����ƶ�nλ
	char str[] = "abcdefg";
	charShift( str, -2 );
	cout << str << endl;

	return 0;
}

void charShift(char* str, int n)
{
	assert(str != nullptr);

	int strLength = strlen(str);
	n %= strLength;
	if (0 == n)
		return;

	string tmp(str);
	auto middle = tmp.begin();

	if (n > 0)
		middle = middle + strLength - n;//tmp.end() - n
	else
		middle += (-n);//tmp.begin() + abs(n)
	//������ת
	rotate( tmp.begin(), middle, tmp.end() );
	//��������Ƶ�ԭ�����ַ�����
	copy( tmp.begin(), tmp.end(), str );
}