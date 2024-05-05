#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 5e2 + 5;

int N;

int cache[MAX];

pair<int, int> p[MAX];

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> p[i].first >> p[i].second;
	}

	sort(p, p + N);

	int idx = 0;
	int result = 0;
	cache[idx] = p[idx].second;

	for (int i = 1; i < N; i++)
	{
		if (p[i].second > cache[idx])
		{
			cache[++idx] = p[i].second;
		}
		else
		{
			int idx2 = lower_bound(cache, cache + idx, p[i].second) - cache;
			cache[idx2] = p[i].second;

			result++;
		}
	}

	cout << result << "\n";

	return 0;
}