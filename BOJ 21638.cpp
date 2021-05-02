#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t1, v1, t2, v2;
	cin >> t1 >> v1 >> t2 >> v2;

	if (t2 < 0 && v2 >= 10)
	{
		cout << "A storm warning for tomorrow! Be careful and stay home if possible!\n";

		return 0;
	}

	if (t2 < t1)
	{
		cout << "MCHS warns! Low temperature is expected tomorrow.\n";

		return 0;
	}

	if (v1 < v2)
	{
		cout << "MCHS warns! Strong wind is expected tomorrow.\n";

		return 0;
	}

	cout << "No message\n";

	return 0;
}