#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;

	if (n <= 5)
	{
		cout << n << "\n";

		return 0;
	}

	int temp = (n - 5) % 8;
	int result;

	if (temp <= 4)
	{
		result = 5 - temp;
	}
	else
	{
		result = temp - 3;
	}

	cout << result << "\n";

	return 0;
}