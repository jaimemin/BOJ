#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (1)
	{
		int N;
		cin >> N;

		if (N == 0)
		{
			break;
		}

		long long a, b, c;
		cin >> a >> b >> c;

		long long result;

		if (b - a == c - b)
		{
			result = N * (2 * a + (N - 1)*(b - a)) / 2;
		}
		else
		{
			long long r = b / a;

			result = a * (pow(r, N) - 1) / (r - 1);
		}

		cout << result << "\n";
	}

	return 0;
}