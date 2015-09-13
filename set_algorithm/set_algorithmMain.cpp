#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>
#include <functional>
using namespace std;

template <typename T>
struct display
{
	void operator()(const T& x)
	{
		cout << x << " ";
	}
};

int main()
{
	int ia1[] = { 1, 3, 5, 7, 9, 11 };
	int ia2[] = { 1, 1, 2, 3, 5, 8, 13 };
	auto output = ostream_iterator<int>(cout, " ");

	multiset<int> S1(begin(ia1), end(ia1));
	multiset<int> S2(begin(ia2), end(ia2));

	for_each(S1.begin(), S1.end(), display<int>()); cout << endl;
	for_each(S2.begin(), S2.end(), display<int>()); cout << endl;

	auto first1(S1.begin());
	auto last1(S1.end());
	auto first2(S2.begin());
	auto last2(S2.end());
	auto ResetBeginIterator = [&]() {
		first1 = S1.begin();
		first2 = S2.begin();
	};

	//����
	cout << "Union of S1 and S2: ";
	set_union(first1, last1, first2, last2, output); cout << endl;
	//1 1 2 3 5 7 8 9 11 13

	//���õ�����
	ResetBeginIterator();
	//����
	cout << "Intersection of S1 and S2:";
	set_intersection(first1, last1, first2, last2, output); cout << endl;
	//1 3 5

	//���õ�����
	ResetBeginIterator();
	//�
	cout << "Difference of S1 and S2 (S1-S2):";
	set_difference(first1, last1, first2, last2, output); cout << endl;
	//7 9 11 

	//���õ�����
	ResetBeginIterator();
	//�ԳƲ
	cout << "Symmetric difference of S1 and S2 (S1-S2):";
	set_symmetric_difference(first1, last1, first2, last2, output); cout << endl;
	//1 2 7 8 9 11 13
	//Ϊɶ����1����Ϊ����stl�����е�set������ѧ���ͬ

	//���õ�����
	ResetBeginIterator();
	//�
	cout << "Difference of S2 and S1 (S2-S1):";
	set_difference(first2, last2, first1, last1, output); cout << endl;
	//1 2 8 13
	//Ϊɶ����1����Ϊ����stl�����е�set������ѧ���ͬ
	return 0;
}