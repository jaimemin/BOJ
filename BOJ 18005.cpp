#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;

	int result;

	if (n % 2)
	{
		result = 0;
	}
	else
	{
		if ((n / 2) % 2)
		{
			result = 1;
		}
		else
		{
			result = 2;
		}
	}

	cout << result << "\n";

	return 0;
}