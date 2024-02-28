#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		if (i % 2)
		{
			cout << " ";
		}

		for (int j = 0; j < N; j++)
		{
			cout << "*";

			if (j != N - 1)
			{
				cout << " ";
			}
		}

		cout << "\n";
	}

	return 0;
}