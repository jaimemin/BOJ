#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N, K;
	cin >> N >> K;

	for (int i = 0; i < K; i++)
	{
		int S, T, R;
		cin >> S >> T >> R;

		int oneRep = S * T;
		int result = 0;
		int repCnt = 0;

		while (true)
		{
			if (N - repCnt <= oneRep)
			{
				result += ceil(double(N - repCnt) / S);

				break;
			}

			repCnt += oneRep;
			result += T + R;
		}

		cout << result << "\n";
	}

	return 0;
}