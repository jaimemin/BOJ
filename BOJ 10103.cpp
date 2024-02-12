#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int A = 100, B = 100;
	int n;
	cin >> n;

	while (n--)
	{
		int a, b;
		cin >> a >> b;

		if (a > b)
		{
			B -= a;
		}
		else if (b > a)
		{
			A -= b;
		}
	}

	cout << A << "\n" << B << "\n";

	return 0;
}