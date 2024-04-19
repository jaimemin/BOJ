#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

const int MAX = 1000 + 1;

int N;

int arr[MAX];

int cache[MAX];

pair<int, int> answer[MAX];

stack<int> s;

int LIS(void)
{
	int idx = 0;
	cache[idx] = arr[0];
	answer[0] = { 0, arr[0] };

	for (int i = 1; i < N; i++)
	{
		if (cache[idx] < arr[i])
		{
			cache[++idx] = arr[i];

			answer[i] = { idx, arr[i] };
		}
		else
		{
			int idx2 = lower_bound(cache, cache + idx, arr[i]) - cache;
			cache[idx2] = arr[i];

			answer[i] = { idx2, arr[i] };
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
		cin >> arr[i];
	}

	int result = LIS();
	int num = result - 1;
	cout << result << "\n";

	for (int i = N - 1; i >= 0; i--)
	{
		if (answer[i].first == num)
		{
			s.push(answer[i].second);

			num--;
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