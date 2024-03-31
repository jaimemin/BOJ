#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

const int MAX = 4;

int N, M;

int result;

int board[MAX][MAX];

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;

	for (int y = 0; y < N; y++)
	{
		string s;
		cin >> s;

		for (int x = 0; x < M; x++)
		{
			board[y][x] = (s[x] - '0');
		}
	}

	for (int bit = 0; bit < (1 << (N * M)); bit++)
	{
		int sum = 0;

		for (int y = 0; y < N; y++)
		{
			int temp = 0;

			for (int x = 0; x < M; x++)
			{
				int k = y * M + x;

				if (!(bit & (1 << k)))
				{
					temp *= 10;
					temp += board[y][x];
				}
				else
				{
					sum += temp;
					temp = 0;
				}
			}

			sum += temp;
		}

		for (int x = 0; x < M; x++)
		{
			int temp = 0;

			for (int y = 0; y < N; y++)
			{
				int k = y * M + x;

				if (bit & (1 << k))
				{
					temp *= 10;
					temp += board[y][x];
				}
				else
				{
					sum += temp;
					temp = 0;
				}
			}

			sum += temp;
		}

		result = max(result, sum);
	}

	cout << result << "\n";

	return 0;
}