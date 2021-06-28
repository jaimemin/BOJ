#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		int N;
		cin >> N;

		long long sum = 0;

		for (int i = 0; i < N; i++)
		{
			int number;
			cin >> number;

			sum += number;
		}

		cout << sum << "\n";
	}

	return 0;
}