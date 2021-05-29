#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	long long N;
	cin >> N;

	int score = 0;

	while (N != 1)
	{
		if (N % 2)
		{
			N = 3 * N + 1;
		}
		else
		{
			N /= 2;
		}

		score++;
	}

	cout << score << "\n";

	return 0;
}