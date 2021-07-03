#include <iostream>
using namespace std;

int main(void)
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++)
	{
		int a, b;
		cin >> a >> b;

		printf("Case %d: %d\n", t, a + b);
	}

	return 0;
}