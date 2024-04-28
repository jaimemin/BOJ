#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

long long X, Y;

long long result = LLONG_MAX;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> X >> Y;

	long long left = 1, right = 1e16;
	long long Z = (Y * 100) / X;

	while (left <= right)
	{
		long long mid = (left + right) / 2;
		long long newZ = ((Y + mid) * 100) / (X + mid);

		if (newZ != Z)
		{
			right = mid - 1;
			
			result = min(result, mid);
		}
		else
		{
			left = mid + 1;
		}
	}

	if (result == LLONG_MAX)
	{
		cout << -1 << "\n";
	}
	else
	{
		cout << result << "\n";
	}

	return 0;
}