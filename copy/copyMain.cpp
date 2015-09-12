#include <iostream>
#include <memory>
#include <string>
#include <iterator>
#include <assert.h>

using namespace std;

void shiftString( char str[], int step );

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
	char str[10] = "hellomt";
	shiftString(str, 2);
	cout << str << endl;

	return 0;
}
















void shiftString(char str[], int step)
{
	assert(str != NULL);
	int strLen = strlen( str );
	int n = step % strLen;
	if (0 == n)
		return;

	int frontPartSize = strLen - n;
	int backPartSize = n;

	string frontPart( str, frontPartSize);
	string backPart( str + frontPartSize, backPartSize  );
	string result( backPart + frontPart );

	copy( result.begin(), result.end(), str );
}