#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (1)
	{
		int a, b, c;
		cin >> a >> b >> c;

		if (a == 0 && b == 0 && c == 0)
		{
			break;
		}

		if ((b > 0 && c <= a) || (b < 0 && c >= a))
		{
			cout << "X\n";

			continue;
		}

		if ((c - a) % b == 0)
		{
			cout << (c - a) / b + 1 << "\n";

			continue;
		}

		cout << "X\n";
	}

	return 0;
}