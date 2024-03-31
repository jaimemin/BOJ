#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int M;
	cin >> M;

	int bit = 0;

	while (M--)
	{
		string op;
		int x;
		cin >> op;

		if (op == "add")
		{
			cin >> x;

			bit |= (1 << x);
		}
		else if (op == "remove")
		{
			cin >> x;

			if (bit & (1 << x))
			{
				bit -= (1 << x);
			}
		}
		else if (op == "check")
		{
			cin >> x;

			cout << ((bit & (1 << x)) ? 1 : 0) << "\n";
		}
		else if (op == "toggle")
		{
			cin >> x;

			bit ^= (1 << x);
		}
		else if (op == "all")
		{
			bit = (1 << 21) - 1;
		}
		else
		{
			bit = 0;
		}
	}

	return 0;
}