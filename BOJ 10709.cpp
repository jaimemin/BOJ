#include <iostream>
#include <string>
using namespace std;

const int MAX = 100;

string board[MAX];

int answer[MAX][MAX];

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int H, W;
	cin >> H >> W;

	for (int i = 0; i < H; i++)
	{
		string s;
		cin >> s;

		board[i] = s;
	}

	for (int y = 0; y < H; y++)
	{
		int prev = -1;

		for (int x = 0; x < W; x++)
		{
			if (board[y][x] == 'c')
			{
				answer[y][x] = 0;

				prev = x;
			}
			else
			{
				answer[y][x] = prev == -1 ? -1 : x - prev;
			}
		}
	}

	for (int y = 0; y < H; y++)
	{
		for (int x = 0; x < W; x++)
		{
			cout << answer[y][x];

			if (x != W - 1)
			{
				cout << " ";
			}
		}
		
		cout << "\n";
	}

	return 0;
}