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
	//�ҵ���һ����ƥ���Ԫ��
	auto mis = mismatch(iv1.begin(), iv1.end(), iv2.begin());
	//���һ��pair, ����firstָ���һ���������Ĳ�ƥ��㣬 secondָ��ڶ����������Ĳ�ƥ���
	//����Ҫ�����ж��Ƿ񲻵���������end()�������������
	if (mis.first != iv1.end())
		cout << *mis.first << " ";
	if (mis.second != iv2.end())
		cout << *mis.second << endl;


	cout << "--------------------------equal----------------------" << endl;
	//�������������[first,last)��������ȣ�����true�����򷵻�false
	//����ڶ����е�Ԫ�رȽ϶࣬�������Ԫ�ز�����
	cout << equal(iv1.begin(), iv1.end(), iv2.begin()) << endl;

	//�Զ���ȽϺ���
	cout << equal(iv1.begin(), iv1.end(), &iv2[3], [](int x, int y)
	{
		return x < y;
	}) << endl;


	cout << "--------------------------fill----------------------" << endl;
	//������ȫ����100
	fill( iv1.begin(), iv1.end(), 100 );
	for_each( iv1.begin(), iv1.end(), display<int> );
	//��ָ��λ�ÿ�ʼ������
	fill_n(iv1.begin(), 2, 99);
	for_each(iv1.begin(), iv1.end(), display<int>);


	cout << "--------------------------iter_swap----------------------" << endl;
	auto iter1 = iv1.begin();	//ָ��99
	auto iter2 = iter1;		
	advance( iter2, 3 );		//ָ��100
	iter_swap( iter1, iter2 );
	cout << *iter1 << " " << *iter2 << endl;
	for_each(iv1.begin(), iv1.end(), display<int>);

	cout << "--------------------------lexicographical_compare----------------------" << endl;
	string stra1[] = {"Jamie", "JJHou", "Jason"};
	string stra2[] = {"Jamie", "JJhou", "Jerry"};
	//�� �ֵ��� ���������н��бȽ�
	cout << lexicographical_compare(stra1, stra1 + 2, stra2, stra2 + 2) << endl;

	cout << lexicographical_compare(stra1, stra1 + 2, stra2, stra2 + 2, greater<string>()) << endl;
	return 0;
}