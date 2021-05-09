#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (true)
	{
		int startingBalance, amount;
		char operation;
		cin >> startingBalance >> operation >> amount;

		if (startingBalance == 0 && operation == 'W' && amount == 0)
		{
			break;
		}

		if (operation == 'W')
		{
			int result = startingBalance - amount;

			if (result < -200)
			{
				cout << "Not allowed\n";

				continue;
			}

			cout << result << "\n";
		}
		else
		{
			int result = startingBalance + amount;

			cout << result << "\n";
		}
	}

	return 0;
}