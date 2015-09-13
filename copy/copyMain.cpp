#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <deque>

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
	{
		int ia[] = { 0,1,2,3,4,5,6,7,8, };
		//����������������䲻�ص���û�г�ͻ
		copy(ia + 2, ia + 7, ia);
		for_each(begin(ia), end(ia), display<int>()); cout << endl;
		//2 3 4 5 6 5 6 7 8 
	}
	//////////////////////////////////////////////////
	{
		int ia[] = { 0,1,2,3,4,5,6,7,8, };
		//������������������ص����п��ܳ�ͻ
		copy(ia + 2, ia + 7, ia+4);
		for_each(begin(ia), end(ia), display<int>()); cout << endl;
		//0 1 2 3 2 3 4 5 6 
		//������ȷ���ײ����memmove����ȷ����
		
	}
	//////////////////////////////////////////////////
	{
		int ia[] = { 0,1,2,3,4,5,6,7,8, };
		//deque ���� has no trivial assignment operator
		deque<int> id( begin(ia), end(ia) );
		auto first = id.begin();
		auto last = id.end();
		auto result = id.begin();
		cout << *result << endl;	//0
		++++first;					//advance(first,2)
		cout << *first << endl;		//2
		----last;					//advance(last,2)
		cout << *last << endl;		//7

		//���������յ����������䲻�ص���û���г�ͻ
		copy( first, last, result );
		for_each(id.begin(), id.end(), display<int>()); cout << endl;
		//2 3 4 5 6 5 6 7 8 
	}
	//////////////////////////////////////////////////
	{
		int ia[] = { 0,1,2,3,4,5,6,7,8, };
		//deque ���� has no trivial assignment operator
		deque<int> id(begin(ia), end(ia));
		auto first = id.begin();
		auto last = id.end();
		auto result = id.begin();
		advance( result, 4 );
		cout << *result << endl;	//4
		++++first;					//advance(first,2)
		cout << *first << endl;		//2
		----last;					//advance(last,2)
		cout << *last << endl;		//7

		//���������յ������������ص����п��ܳ�ͻ
		copy(first, last, result);
		for_each(id.begin(), id.end(), display<int>()); cout << endl;
		//0 1 2 3 2 3 2 3 2
		//����������Ϊcopy�㷨����ʹ��memmove����Ϊdeque ���� has no assignment operator��
		//��ע�⣬ʹ��vector����deque���в��ԣ����ƽ��������ȷ�ģ���Ϊvector�ĵ��������Ǹ�ԭ��ָ��
	}



	return 0;
}
