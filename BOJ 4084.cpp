#include <iostream>
#include <cmath>
using namespace std;

int func(int a, int b, int c, int d, int cnt)
{
	if (a == b && b == c && c == d && d == a)
	{
		return cnt;
	}

	return func(abs(a - b), abs(b - c), abs(c - d), abs(d - a), cnt + 1);
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (1)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;

		if (a == 0 && b == 0 && c == 0 && d == 0)
		{
			break;
		}

		cout << func(a, b, c, d, 0) << "\n";
	}

	return 0;
}