#include <iostream>
using namespace std;

void printJBox(int n)
{
	if (n == 1)
	{
		cout << "#\n";

		return;
	}

	for (int i = 0; i < n; i++)
	{
		cout << "#";
	}
	
	cout << "\n";

	for (int i = 0; i < n - 2; i++)
	{
		cout << "#";

		for (int j = 0; j < n - 2; j++)
		{
			cout << "J";
		}

		cout << "#\n";
	}

	for (int i = 0; i < n; i++)
	{
		cout << "#";
	}

	cout << "\n";
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		int n;
		cin >> n;

		printJBox(n);

		if (t < T - 1)
		{
			cout << "\n";
		}
	}

	return 0;
}