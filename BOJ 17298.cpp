#include <iostream>
#include <stack>
using namespace std;

const int MAX = 1e6;

int arr[MAX];

int result[MAX];

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	stack<pair<int, int>> st;
	

	for (int i = 0; i < N; i++)
	{
		while (!st.empty() && arr[i] > st.top().first)
		{
			result[st.top().second] = arr[i];
			st.pop();
		}

		st.push({ arr[i], i });
	}

	while (!st.empty())
	{
		result[st.top().second] = -1;
		st.pop();
	}

	for (int i = 0; i < N; i++)
	{
		cout << result[i];

		if (i != N - 1)
		{
			cout << " ";
		}
	}

	cout << "\n";
	
	return 0;
}