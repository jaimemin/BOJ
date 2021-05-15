#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (1)
	{
		int A, B, C, D;
		cin >> A >> B >> C >> D;

		if (A == 0 && B == 0 && C == 0 && D == 0)
		{
			break;
		}

		if (A < B)
		{
			swap(A, B);
		}

		if (C < D)
		{
			swap(C, D);
		}

		int start = 1, end = 100;
		int result;

		while (start <= end)
		{
			int mid = (start + end) / 2;

			if (A * mid <= C * 100 
				&& B * mid <= D * 100)
			{
				start = mid + 1;

				result = mid;
			}
			else
			{
				end = mid - 1;
			}
		}

		cout << result << "%\n";
	}

	return 0;
}