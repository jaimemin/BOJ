#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;

	int result = 1;

	for (int i = 2; i <= n; i++)
	{
		result *= i;

		result %= 10;
	}

	cout << result << "\n";

	return 0;
}