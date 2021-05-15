#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;

	for (int t = 0;t < T; t++)
	{
		int n;
		cin >> n;

		int player1 = 0, player2 = 0;

		for (int i = 0; i < n; i++)
		{
			char a, b;
			cin >> a >> b;

			switch (a)
			{
			case 'R':
				if (b == 'R')
				{
					player1++;
					player2++;
				}
				else if (b == 'P')
				{
					player2++;
				}
				else
				{
					player1++;
				}

				break;
			case 'P':
				if (b == 'R')
				{
					player1++;
				}
				else if (b == 'P')
				{
					player1++;
					player2++;
				}
				else
				{
					player2++;
				}

				break;
			case 'S':
				if (b == 'R')
				{
					player2++;
				}
				else if (b == 'P')
				{
					player1++;
				}
				else
				{
					player1++;
					player2++;
				}

				break;
			}
		}

		if (player1 > player2)
		{
			cout << "Player 1\n";
		}
		else if (player1 == player2)
		{
			cout << "TIE\n";
		}
		else
		{
			cout << "Player 2\n";
		}
	}

	return 0;
}