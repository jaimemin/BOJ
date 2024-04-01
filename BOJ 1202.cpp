#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N, K;
	cin >> N >> K;

	vector<pair<int, int>> jewelries;

	for (int i = 0; i < N; i++)
	{
		int M, V;
		cin >> M >> V;

		jewelries.push_back({ M, V });
	}

	vector<int> weights;

	for (int k = 0; k < K; k++)
	{
		int weight;
		cin >> weight;

		weights.push_back(weight);
	}

	sort(jewelries.begin(), jewelries.end());
	sort(weights.begin(), weights.end());

	priority_queue<long long> pq;
	int idx = 0;
	long long result = 0;

	for (int k = 0; k < K; k++)
	{
		while (idx < N && jewelries[idx].first <= weights[k])
		{
			pq.push(jewelries[idx++].second);
		}

		if (!pq.empty())
		{
			result += pq.top();

			pq.pop();
		}
	}

	cout << result << "\n";

	return 0;
}