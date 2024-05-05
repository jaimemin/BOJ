#include <iostream>
#include <algorithm>
#include <cstring>
#include <stack>
using namespace std;

const int MAX = 1e6 + 1e3;

int N;

int A[MAX];

int cache[MAX];

pair<int, int> answer[MAX];

stack<int> s;

int func(void)
{
	int idx = 0;
	cache[idx] = A[idx];
	answer[idx] = { idx, A[idx] };

	for (int i = 1; i < N; i++)
	{
		if (cache[idx] < A[i])
		{
			cache[++idx] = A[i];
			answer[i] = { idx, A[i] };
		}
		else
		{
			int idx2 = lower_bound(cache, cache + idx, A[i]) - cache;
			cache[idx2] = A[i];
			answer[i] = { idx2, A[i] };
		}
	}

	return idx + 1;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}

	int len = func();
	cout << len << "\n";

	int idx = len - 1;

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
		cout << s.top() << " ";

		s.pop();
	}

	cout << "\n";

	return 0;
}