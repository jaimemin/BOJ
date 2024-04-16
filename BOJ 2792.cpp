#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

const int MAX = 3e5 + 3e2;

int N, M;

long long result = LLONG_MAX;

long long jewerlies[MAX];

bool check(long long mid)
{
	long long cnt = 0;

	for (int i = 0; i < M; i++)
	{
		cnt += jewerlies[i] / mid;

		if (jewerlies[i] % mid)
		{
			cnt++;
		}
	}

	return N >= cnt;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;

	long long left = 1, right = 0;

	for (int i = 0; i < M; i++)
	{
		cin >> jewerlies[i];

		right = max(right, jewerlies[i]);
	}

	while (left <= right)
	{
		long long mid = (left + right) / 2;

		if (check(mid))
		{
			right = mid - 1;

			result = min(result, mid);
		}
		else
		{
			left = mid + 1;
		}
	}

	cout << result << "\n";

	return 0;
}