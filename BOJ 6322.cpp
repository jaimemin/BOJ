#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{
	int testCase = 1;

	while (1)
	{
		int a, b, c;
		cin >> a >> b >> c;

		if (a == 0 && b == 0 && c == 0)
		{
			break;
		}

		printf("Triangle #%d\n", testCase++);

		char side;
		double result;

		if (a == -1)
		{
			side = 'a';

			result = c * c - b * b > 0 ? sqrt(c * c - b * b) : -1;
		}
		else if (b == -1)
		{
			side = 'b';

			result = c * c - a * a > 0 ? sqrt(c * c - a * a) : -1;
		}
		else
		{
			side = 'c';

			result = sqrt(a * a + b * b);
		}

		if (result <= 0)
		{
			cout << "Impossible.\n\n";

			continue;
		}

		printf("%c = %.3lf\n\n", side, result);
	}

	return 0;
}