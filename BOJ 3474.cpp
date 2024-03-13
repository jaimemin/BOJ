#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;

	while (T--)
	{
		int N;
		cin >> N;

		int twoCnt = 0, fiveCnt = 0;

		for (int j = 2; j <= N; j *= 2)
		{
			twoCnt += N / j;
		}

		for (int j = 5; j <= N; j *= 5)
		{
			fiveCnt += N / j;
		}

		cout << min(twoCnt, fiveCnt) << "\n";
	}

	return 0;
}