#include <iostream>
#include <climits>
using namespace std;

const int MAX = 1e5;

int N, M;

int arr[MAX];

bool check(int mid)
{
	int num = 1;
	int sum = mid;

	for (int i = 0; i < N; i++)
	{
		if (arr[i] > mid)
		{
			return false;
		}

		if (arr[i] > sum)
		{
			sum = mid;
			num++;
		}

		sum -= arr[i];
	}

	return M >= num;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	int left = 1, right = 1e9;
	int result = INT_MAX;

	while (left <= right)
	{
		int mid = (left + right) / 2;

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