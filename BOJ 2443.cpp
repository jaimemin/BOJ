#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;

	for (int i = N; i >= 1; i--)
	{
		for (int j = 0; j < N - i; j++)
		{
			cout << " ";
		}

		int starCnt = i * 2 - 1;

		for (int j = 0; j < starCnt; j++)
		{
			cout << "*";
		}

		cout << "\n";
	}

	return 0;
}