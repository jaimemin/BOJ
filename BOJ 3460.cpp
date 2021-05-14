#include <iostream>
using namespace std;

void printBitLocations(int n)
{
	int idx = 0;

	while (n)
	{
		if (n % 2)
		{
			cout << idx << " ";
		}

		n /= 2;
		idx++;
	}

	cout << "\n";
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;

	for (int t = 0;t < T; t++)
	{
		int n;
		cin >> n;

		printBitLocations(n);
	}

	return 0;
}