#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;

	vector<pair<int, int>> v(N);

	for (int i = 0; i < N; i++)
	{
		int left, right;
		cin >> left >> right;

		v[i] = { right, left };
	}

	sort(v.begin(), v.end());

	int result = 0;
	int time = 0;

	for (int i = 0; i < N; i++)
	{
		if (v[i].second < time)
		{
			continue;
		}

		time = v[i].first;
		result++;
	}

	cout << result << "\n";

	return 0;
}