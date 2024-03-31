#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int X;
	cin >> X;

	int N = 64;
	int result = 0;
	int idx = 0;

	while (X)
	{
		if (N > X)
		{
			N /= 2;
			idx++;

			continue;
		}

		result++;
		X -= 1 << (6 - idx);
	}

	cout << result << "\n";

	return 0;
}