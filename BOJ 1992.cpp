#include <iostream>
#include <string>
using namespace std;

const int MAX = 64;

string quadTree[MAX];

void func(int y, int x, int N)
{
	if (N == 1)
	{
		cout << quadTree[y][x];

		return;
	}

	bool zero = true, one = true;

	for (int i = y; i < y + N; i++)
	{
		for (int j = x; j < x + N; j++)
		{
			if (quadTree[i][j] == '1')
			{
				zero = false;
			}
			else
			{
				one = false;
			}
		}
	}

	if (zero)
	{
		cout << 0;
	}
	else if (one)
	{
		cout << 1;
	}
	else
	{
		cout << "(";
		func(y, x, N / 2);
		func(y, x + N / 2, N / 2);
		func(y + N / 2, x, N / 2);
		func(y + N / 2, x + N / 2, N / 2);
		cout << ")";
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> quadTree[i];
	}

	func(0, 0, N);

	return 0;
}