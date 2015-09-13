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
		//输出区间与输入区间不重叠，没有冲突
		copy(ia + 2, ia + 7, ia);
		for_each(begin(ia), end(ia), display<int>()); cout << endl;
		//2 3 4 5 6 5 6 7 8 
	}
	//////////////////////////////////////////////////
	{
		int ia[] = { 0,1,2,3,4,5,6,7,8, };
		//输出区间与输入区间重叠，有可能冲突
		copy(ia + 2, ia + 7, ia+4);
		for_each(begin(ia), end(ia), display<int>()); cout << endl;
		//0 1 2 3 2 3 4 5 6 
		//本例正确，底层调用memmove，正确复制
		
	}
	//////////////////////////////////////////////////
	{
		int ia[] = { 0,1,2,3,4,5,6,7,8, };
		//deque 具有 has no trivial assignment operator
		deque<int> id( begin(ia), end(ia) );
		auto first = id.begin();
		auto last = id.end();
		auto result = id.begin();
		cout << *result << endl;	//0
		++++first;					//advance(first,2)
		cout << *first << endl;		//2
		----last;					//advance(last,2)
		cout << *last << endl;		//7

		//输出区间的终点与输入区间不重叠，没有有冲突
		copy( first, last, result );
		for_each(id.begin(), id.end(), display<int>()); cout << endl;
		//2 3 4 5 6 5 6 7 8 
	}
	//////////////////////////////////////////////////
	{
		int ia[] = { 0,1,2,3,4,5,6,7,8, };
		//deque 具有 has no trivial assignment operator
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

		//输出区间的终点与输入区间重叠，有可能冲突
		copy(first, last, result);
		for_each(id.begin(), id.end(), display<int>()); cout << endl;
		//0 1 2 3 2 3 2 3 2
		//本例错误，因为copy算法不再使用memmove（因为deque 具有 has no assignment operator）
		//请注意，使用vector代替deque进行测试，复制结果将是正确的，因为vector的迭代器就是个原生指针
	}



	return 0;
}
