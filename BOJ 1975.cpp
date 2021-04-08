#include <iostream>
using namespace std;

int getLastConsecutiveZeros(int N, int decimal)
{
	int zeros = 0;

	while (N)
	{
		if (N%decimal)
		{
			break;
		}

		zeros++;
		N /= decimal;
	}

	return zeros;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		int N;
		cin >> N;

		if (N == 1)
		{
			cout << 0 << "\n";

			continue;
		}

		int result = 1;

		for (int i = 2; i < N; i++)
		{
			result += getLastConsecutiveZeros(N, i);
		}

		cout << result << "\n";
	}

	return 0;
}