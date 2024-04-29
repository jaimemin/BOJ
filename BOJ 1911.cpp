#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N, L;
	cin >> N >> L;

	vector<pair<int, int>> v;

	for (int i = 0; i < N; i++)
	{
		int start, end;
		cin >> start >> end;

		v.push_back({ start, end });
	}

	sort(v.begin(), v.end());

	int result = 0;
	int idx = 0;

	for (int i = 0; i < N; i++)
	{
		if (idx >= v[i].second)
		{
			continue;
		}

		idx = max(idx, v[i].first);

		int cnt = (v[i].second - (idx + 1)) / L + 1;
		result += cnt;
		idx += (L * cnt);
	}

	cout << result << "\n";

	return 0;
}