#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;

const int MAX = 1e4;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;

	vector<pair<int, int>> v;

	while (n--)
	{
		int p, d;
		cin >> p >> d;

		v.push_back({ d, p });
	}

	sort(v.begin(), v.end());

	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 0; i < v.size(); i++)
	{
		pq.push(v[i].second);

		if (pq.size() > v[i].first)
		{
			pq.pop();
		}
	}

	int result = 0;

	while (!pq.empty())
	{
		result += pq.top();

		pq.pop();
	}

	cout << result << "\n";

	return 0;
}