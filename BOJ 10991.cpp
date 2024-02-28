#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;

	for (int k = 1; k <= N; k++)
	{
		for (int i = 0; i < N - k; i++)
		{
			cout << " ";
		}
		
		for (int i = 0; i < k; i++)
		{
			cout << "*";

			if (i != k - 1)
			{
				cout << " ";
			}
		}

		cout << "\n";
	}

	return 0;
}