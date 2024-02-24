#include <iostream>
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

		int cSum = 0;
		double gSum = 0;

		for (int i = 0; i < N; i++)
		{
			int C;
			double G;
			cin >> C >> G;

			cSum += C;
			gSum += (G * (double) C);
		}

		printf("%d %.1f\n", cSum, gSum / (double) cSum);
	}

	return 0;
}