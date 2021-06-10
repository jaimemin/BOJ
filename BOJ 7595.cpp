#include <iostream>
using namespace std;

void printTriangle(int n)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			cout << "*";
		}

		cout << "\n";
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (1)
	{
		int n;
		cin >> n;

		if (n == 0)
		{
			break;
		}

		printTriangle(n);
	}

	return 0;
}