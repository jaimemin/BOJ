#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 1e5;

int N;

int arr[MAX];

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	sort(arr, arr + N);

	int temp = arr[0];
	int result = 1;

	for (int i = 1; i < N; i++)
	{
		if (arr[i] < temp * 2)
		{
			continue;
		}

		temp = arr[i];
		result++;
	}

	cout << result << "\n";

	return 0;
}
