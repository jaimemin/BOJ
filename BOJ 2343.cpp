#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

const int MAX = 1e5;

int N, M;

int lectures[MAX];

bool check(int mid)
{
	int cnt = 1;
	int idx = 0;
	vector<int> blueray(M, mid);

	for (int i = 0; i < N; i++)
	{
		if (blueray[idx] >= lectures[i])
		{
			blueray[idx] -= lectures[i];
		}
		else
		{
			if (++idx == M)
			{
				return false;
			}

			if (blueray[idx] >= lectures[i])
			{
				blueray[idx] -= lectures[i];
			}
			else
			{
				return false;
			}
		}
	}

	return true;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> lectures[i];
	}

	int left = 1, right = 1e9;
	int result = INT_MAX;

	while (left <= right)
	{
		int mid = (left + right) / 2;

		if (check(mid))
		{
			result = min(result, mid);
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}

	cout << result << "\n";

	return 0;
}