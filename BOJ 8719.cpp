#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int testCase;
	cin >> testCase;

	for (int t = 0; t < testCase; t++)
	{
		int x, w;
		cin >> x >> w;

		int result = 0;

		while (x < w)
		{
			x *= 2;

			result++;
		}

		cout << result << "\n";
	}

	return 0;
}