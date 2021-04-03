#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int M;
	cin >> M;

	int ball = 1;

	for (int m = 0; m < M; m++)
	{
		int X, Y;
		cin >> X >> Y;

		if (X == ball || Y == ball)
		{
			ball = (X == ball ? Y : X);
		}
	}

	cout << ball << "\n";

	return 0;
}