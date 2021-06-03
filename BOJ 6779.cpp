#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{
	int h, M;
	cin >> h >> M;

	int hour = M;

	for (int t = 1; t <= M; t++)
	{
		if (-6 * pow(t, 4) + h * pow(t, 3) + 2 * pow(t, 2) + t <= 0)
		{
			cout << "The balloon first touches ground at hour: " << t << "\n";

			return 0;
		}
	}

	cout << "The balloon does not touch ground in the given time.\n";

	return 0;
}