#include <iostream>
#include <cmath>
using namespace std;

const int HOUR2SECONDS = 3600;
const int MINUTE2SECONDS = 60;

int main(void)
{
	while (1)
	{
		int M, A, B;
		cin >> M >> A >> B;

		if (M == 0 && A == 0 && B == 0)
		{
			break;
		}

		double aDuration = M / (double)A * HOUR2SECONDS;
		double bDuration = M / (double)B * HOUR2SECONDS;

		int diff = round(abs(aDuration - bDuration));

		printf("%d:%02d:%02d\n", diff / HOUR2SECONDS, diff % HOUR2SECONDS / MINUTE2SECONDS, diff % HOUR2SECONDS % MINUTE2SECONDS);
	}

	return 0;
}