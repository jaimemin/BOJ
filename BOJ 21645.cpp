#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m, k;
	cin >> n >> m >> k;

	long long result;

	if (m < k)
	{
		result = n * m;
	}
	else
	{
		result = n * ((k - 1) + m / k);
	}

	cout << result << "\n";

	return 0;
}