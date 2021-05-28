#include <iostream>
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

		int maryCnt = 0;
		int johnCnt = 0;

		for (int i = 0; i < N; i++)
		{
			int R;
			cin >> R;

			R == 0 ? maryCnt++ : johnCnt++;
		}

		printf("Mary won %d times and John won %d times\n", maryCnt, johnCnt);
	}

	return 0;
}