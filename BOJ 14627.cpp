#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 1e6;

long long S, C;

int arr[MAX];

bool check(long long mid)
{
	long long cnt = 0;

	for (int a : arr)
	{
		cnt += a / mid;
	}

	return cnt >= C;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> S >> C;

	for (int i = 0; i < S; i++)
	{
		cin >> arr[i];
	}

	long long left = 1, right = 1e18;
	long long len = 0;

	while (left <= right)
	{
		long long mid = (left + right) / 2;

		if (check(mid))
		{
			len = mid;
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}

	long long result = 0;;
	long long cnt = 0;

	for (int a : arr)
	{
		for (int i = 0; i < a / len; i++)
		{
			cnt++;
			
			if (cnt > C)
			{
				result += len;
			}
		}

		result += a % len;
	}

	cout << result << "\n";

	return 0;
}