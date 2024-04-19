#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 1e3 + 1e2;

int arr[MAX];

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;

	int len = 0;

	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;

		auto idx = lower_bound(arr, arr + len, num);
		
		if (*idx == 0)
		{
			len++;
		}

		*idx = num;
	}

	cout << len << "\n";

	return 0;
}