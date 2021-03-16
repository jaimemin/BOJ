#include <iostream>
using namespace std;

void printResult(int x, int y)
{
	if (x > 0)
	{
		if (y > 0)
		{
			cout << 1 << "\n";
		}
		else
		{
			cout << 4 << "\n";
		}
	}
	else
	{
		if (y > 0)
		{
			cout << 2 << "\n";
		}
		else
		{
			cout << 3 << "\n";
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int x, y;
	cin >> x >> y;

	printResult(x, y);

	return 0;
}