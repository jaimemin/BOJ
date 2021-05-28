#include <iostream>
using namespace std;

const int MAX = 500;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;

	int result = 0;

	for (int i = 1; i <= MAX; i++)
	{
		for (int j = i + 1; j <= MAX; j++)
		{
			if (j * j == i * i + N)
			{
				result++;
			}
		}
	}

	cout << result << "\n";

	return 0;
}