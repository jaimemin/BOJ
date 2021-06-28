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
		int n, m;
		cin >> n >> m;

		int result = 0;

		for (int a = 1;a < n; a++)
		{
			for (int b = a + 1; b < n; b++)
			{
				int temp = a * a + b * b + m;

				if (temp % (a * b) == 0)
				{
					result++;
				}
			}
		}

		cout << result << "\n";
	}

	return 0;
}