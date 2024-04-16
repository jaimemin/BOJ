#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

bool check(int target)
{
	int left = 0, right = v.size() - 1;
	
	while (left <= right)
	{
		int mid = (left + right) / 2;

		if (v[mid] > target)
		{
			right = mid - 1;
		}
		else if (v[mid] < target)
		{
			left = mid + 1;
		}
		else
		{
			return true;
		}
	}

	return false;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;

	while (T--)
	{
		v.clear();
		int N;
		cin >> N;

		v.resize(N);

		for (int i = 0; i < N; i++)
		{
			cin >> v[i];
		}

		sort(v.begin(), v.end());

		int M;
		cin >> M;

		for (int i = 0; i < M; i++)
		{
			int target;
			cin >> target;

			cout << check(target) << "\n";
		}
	}

	return 0;
}