#include <iostream>
using namespace std;

const int MAX = 3;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int Z;
	cin >> Z;

	for (int z = 0; z < Z; z++)
	{
		double adamPercentage[MAX];
		double gosiaPercentage[MAX];

		for (int i = 0; i < MAX; i++)
		{
			cin >> adamPercentage[i];
		}

		for (int i = 0; i < MAX; i++)
		{
			cin >> gosiaPercentage[i];
		}

		double adam = 0, gosia = 0;

		for (int i = 0; i < MAX; i++)
		{
			adam += adamPercentage[i] * gosiaPercentage[(i + 1) % MAX];
			gosia += adamPercentage[i] * gosiaPercentage[(i + 2) % MAX];
		}

		if (adam > gosia)
		{
			cout << "ADAM\n";
		}
		else if (adam == gosia)
		{
			cout << "=\n";
		}
		else
		{
			cout << "GOSIA\n";
		}
	}

	return 0;
}