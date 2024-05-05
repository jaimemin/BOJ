#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

const int MAX = 5e5 + 5e2;

int N;

int cache[MAX];

bool visited[MAX];

pair<int, int> p[MAX];

pair<int, int> answer[MAX];

stack<int> s;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> p[i].first >> p[i].second;

		visited[p[i].first] = true;
	}

	sort(p, p + N);

	int idx = 0;
	int result = 0;
	cache[idx] = p[idx].second;
	answer[idx] = { idx, p[idx].first };

	for (int i = 1; i < N; i++)
	{
		if (p[i].second > cache[idx])
		{
			cache[++idx] = p[i].second;

			answer[i] = { idx, p[i].first };
		}
		else
		{
			int idx2 = lower_bound(cache, cache + idx, p[i].second) - cache;
			cache[idx2] = p[i].second;

			answer[i] = { idx2, p[i].first };
		}
	}

	cout << N - (idx + 1) << "\n";

	for (int i = N - 1; i >= 0; i--)
	{
		if (answer[i].first == idx)
		{
			s.push(answer[i].second);

			idx--;
		}
	}

	while (!s.empty())
	{
		visited[s.top()] = false;

		s.pop();
	}

	for (int i = 0; i < N; i++)
	{
		if (visited[i])
		{
			cout << i << "\n";
		}
	}

	return 0;
}