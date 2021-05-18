#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		int k;
		cin >> k;

		int evenSum = 0, oddSum = 0;

		for (int i = 0; i < k; i++)
		{
			int num;
			cin >> num;

			if (num % 2)
			{
				oddSum += num;

				continue;
			}

			evenSum += num;
		}

		if (evenSum > oddSum)
		{
			cout << "EVEN\n";
		}
		else if (evenSum == oddSum)
		{
			cout << "TIE\n";
		}
		else
		{
			cout << "ODD\n";
		}
	}

	return 0;
}