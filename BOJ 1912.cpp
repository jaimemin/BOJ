#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 1e5 + 1e3;

int n;

int arr[MAX];

int cache[MAX];

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	cache[0] = arr[0];

	for (int i = 1; i < n; i++)
	{
		cache[i] = arr[i];

		if (cache[i - 1] + arr[i] > cache[i])
		{
			cache[i] = cache[i - 1] + arr[i];
		}
	}

	int result = cache[0];

	for (int i = 1; i < n; i++)
	{
		result = max(result, cache[i]);
	}

	cout << result << "\n";

	return 0;
}