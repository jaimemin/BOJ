#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (true)
	{
		string title;
		cin >> title;

		if (title == "#")
		{
			break;
		}

		int M, S, T;
		cin >> M >> S >> T;

		for (int t = 0; t < T; t++)
		{
			char transaction;
			int cnt;
			cin >> transaction >> cnt;

			if (transaction == 'S')
			{
				S = max(0, S - cnt);
			}
			else
			{
				S = min(M, S + cnt);
			}
		}

		cout << title << " " << S << "\n";
	}

	return 0;
}