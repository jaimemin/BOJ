#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
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
		int deadline, ramen;
		cin >> deadline >> ramen;

		v.push_back({ deadline, ramen });
	}

	sort(v.begin(), v.end());

	priority_queue<int, vector<int>, greater<int>> pq;
	
	for (int i = 0; i < N; i++)
	{
		pq.push(v[i].second);

		if (pq.size() > v[i].first)
		{
			pq.pop();
		}
	}

	long long result = 0;

	while (!pq.empty())
	{
		result += pq.top();

		pq.pop();
	}

	cout << result << "\n";

	return 0;
}