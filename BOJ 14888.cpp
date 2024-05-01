#include <iostream>
#include <climits>
using namespace std;

const int MAX = 100;

int N;

int maxResult, minResult;

int A[MAX];

int op[4];

void func(int idx, int total)
{
	if (idx == N - 1)
	{
		maxResult = max(maxResult, total);
		minResult = min(minResult, total);

		return;
	}

	for (int i = 0; i < 4; i++)
	{
		if (op[i])
		{
			op[i]--;
			
			switch (i)
			{
			case 0:
				func(idx + 1, total + A[idx + 1]);

				break;
			case 1:
				func(idx + 1, total - A[idx + 1]);

				break;
			case 2:
				func(idx + 1, total * A[idx + 1]);

				break;
			case 3:
				func(idx + 1, total / A[idx + 1]);

				break;
			}

			op[i]++;
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}

	for (int i = 0; i < 4; i++)
	{
		cin >> op[i];
	}

	maxResult = INT_MIN;
	minResult = INT_MAX;

	func(0, A[0]);

	cout << maxResult << "\n" << minResult << "\n";

	return 0;
}