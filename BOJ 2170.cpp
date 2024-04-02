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

	vector<pair<int, int>> v;

	for (int i = 0; i < N; i++)
	{
		int x, y;
		cin >> x >> y;

		v.push_back({ x, y });
	}

	sort(v.begin(), v.end());

	int left = v[0].first;
	int right = v[0].second;
	int result = 0;

	for (int i = 1; i < N; i++)
	{
		if (right < v[i].first)
		{
			result += (right - left);

			left = v[i].first;
			right = v[i].second;
		}
		else if (v[i].first <= right && right <= v[i].second)
		{
			right = v[i].second;
		}
	}

	result += (right - left);

	cout << result << "\n";

	return 0;
}