#include <iostream>
#include <stack>
using namespace std;

const int MAX = 5e5;

int heights[MAX];

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> heights[i];
	}

	long long result = 0;
	stack<pair<int, long long>> st;

	for (int i = 0; i < N; i++)
	{
		int cnt = 1;

		while (!st.empty() && st.top().first <= heights[i])
		{
			result += st.top().second;
			cnt = (st.top().first == heights[i]) ? st.top().second + 1 : 1;
			
			st.pop();
		}

		if (!st.empty()) // st.top().first > heights[i]
		{
			result++;
		}

		st.push({ heights[i], cnt });
	}

	cout << result << "\n";

	return 0;
}