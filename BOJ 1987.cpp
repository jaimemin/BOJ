#include <iostream>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

const int ALPHABET_MAX = 26;

const int MAX = 20;

typedef struct
{
	int y, x;
} Dir;

Dir moveDir[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

string s[MAX];

int R, C;

int result;

bool visited[ALPHABET_MAX];

void func(int y, int x, int cnt)
{
	result = max(result, cnt);

	for (int k = 0; k < 4; k++)
	{
		int nextY = y + moveDir[k].y;
		int nextX = x + moveDir[k].x;

		if (nextY < 0 || nextY >= R || nextX < 0 || nextX >= C)
		{
			continue;
		}

		if (visited[s[nextY][nextX] - 'A'])
		{
			continue;
		}

		visited[s[nextY][nextX] - 'A'] = true;
		func(nextY, nextX, cnt + 1);
		visited[s[nextY][nextX] - 'A'] = false;
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> R >> C;

	for (int y = 0; y < R; y++)
	{
		cin >> s[y];
	}

	visited[s[0][0] - 'A'] = true;

	func(0, 0, 1);

	cout << result << "\n";

	return 0;
}