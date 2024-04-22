#include <iostream>
using namespace std;

const int MAX = 1e4 + 1;

int arr[MAX];

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;

		arr[num]++;
	}

	for (int i = 1; i <= MAX; i++)
	{
		for (int j = 0; j < arr[i]; j++)
		{
			cout << i << "\n";
		}
	}

	return 0;
}