#include <iostream>
using namespace std;

const int MAX = 10000;

long long N, M;

long long result;

long long arr[MAX];

bool check(long long mid)
{
	long long cnt = M;

	for (int i = 0; i < M; i++)
	{
		cnt += mid / arr[i];
	}

	return cnt >= N;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		cin >> arr[i];
	}

	if (N <= M)
	{
		cout << N << "\n";

		return 0;
	}

	long long left = 0, right = 6e10 + 6;

	while (left <= right)
	{
		long long mid = (left + right) / 2;

		if (check(mid))
		{
			result = mid;
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}

	long long cnt = M;

	for (long long i = 0; i < M; i++)
	{
		cnt += ((result - 1) / arr[i]);
	}

	for (long long i = 0; i < M; i++)
	{
		if (result % arr[i] == 0)
		{
			cnt++;
		}

		if (cnt == N)
		{
			cout << i + 1 << "\n";

			return 0;
		}
	}

	return 0;
}