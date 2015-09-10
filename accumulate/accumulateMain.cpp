//��ʹ�ñȽ�����֧��c++11���Եı��������б���
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int main()
{
	int ia[5] = { 1,2,3,4,5 };
	vector<int> iv(ia, ia + 5);
	//�����ܺ�
	cout << accumulate(iv.begin(), iv.end(), 0) << endl;
	//����2���ܺ�
	cout << accumulate(iv.begin(), iv.end(), 0, [](int init, int b) {return init + 2 * b; }) << endl;
	//����ż�����ܺ�
	cout << accumulate(iv.begin(), iv.end(), 0, [](int init, int b)
	{
		if (b % 2 == 0)
			return init + b;
		return init;
	}) << endl;
	//������ˣ�ע��init��ֵ��ҪΪ1
	cout << accumulate(iv.begin(), iv.end(), 1, [](int init, int b)
	{
		return init * b;
	}) << endl;

	//���㷽��
	double ave = accumulate(iv.begin(), iv.end(), 0.0) / iv.size();
	auto variance = accumulate(iv.begin(), iv.end(), 0.0, [&](double init, int b)
	{
		return init + (b - ave)*(b - ave);
	});
	variance /= iv.size();
	cout << variance << endl;
}