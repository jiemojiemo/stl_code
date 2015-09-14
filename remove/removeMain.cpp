#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

template <typename T>
void display(const T& x)
{
	cout << x << " ";
}
int main()
{
	int ia[] = {0,1,2,3,4,5,6,6,6,7,8};
	vector<int> iv( begin(ia), end(ia) );

	remove(iv.begin(), iv.end(), 6);
	for_each(iv.begin(), iv.end(), display<int>);

	return 0;
}
