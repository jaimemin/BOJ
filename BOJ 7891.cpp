#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;

	for (int t = 0;t < T; t++)
	{
		long long x, y;
		cin >> x >> y;

		long long result = x + y;

		cout << result << "\n";
	}

	return 0;
}