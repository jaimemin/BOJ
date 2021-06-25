#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;

	for (int i = 2; i < n - 1; i++)
	{
		if (n%i)
		{
			cout << i << " ";

			break;
		}
	}

	for (int i = n - 1; i >= 2; i--)
	{
		if (n%i)
		{
			cout << i << "\n";

			break;
		}
	}

	return 0;
}