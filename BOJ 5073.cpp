#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 3;

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

		int sides[MAX] = { a, b, c };

		sort(sides, sides + MAX);

		if (sides[2] >= sides[1] + sides[0])
		{
			cout << "Invalid\n";

			continue;
		}

		if (a == b && b == c && c == a)
		{
			cout << "Equilateral\n";
			
			continue;
		}

		if (a == b || b == c || c == a)
		{
			cout << "Isosceles\n";

			continue;
		}

		cout << "Scalene\n";
	}

	return 0;
}