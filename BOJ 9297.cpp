#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int testCase;
	cin >> testCase;

	for (int t = 1; t <= testCase; t++)
	{
		int n, d;
		cin >> n >> d;

		int quotient = n / d;
		int remainder = n % d;

		cout << "Case " << t << ": ";

		if (quotient && remainder)
		{
			cout << quotient << " " << remainder << "/" << d << "\n";
		}
		else if (quotient)
		{
			cout << quotient << "\n";
		}
		else if (remainder)
		{
			cout << remainder << "/" << d << "\n";
		}
		else
		{
			cout << 0 << "\n";
		}
	}

	return 0;
}