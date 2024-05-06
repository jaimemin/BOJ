#include <iostream>
using namespace std;

const int MAX = 100 + 1;

int N;

int cache[MAX];

pair<int, int> arr[MAX];

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i].first;
	}

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i].second;
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 100; j > arr[i].first; j--)
		{
			cache[j] = max(cache[j], arr[i].second + cache[j - arr[i].first]);
		}
	}

	cout << cache[100] << "\n";

	return 0;
}