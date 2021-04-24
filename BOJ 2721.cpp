#include <iostream>
using namespace std;

int getTn(int n)
{
	return n * (n + 1) / 2;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		int n;
		cin >> n;

		int result = 0;

		for (int i = 1; i <= n; i++)
		{
			result += i * getTn(i + 1);
		}

		cout << result << "\n";
	}

	return 0;
}