#include <iostream>
using namespace std;

int Z(int N, int r, int c)
{
	if (N == 0)
	{
		return 1;
	}

	int size = 1 << (N - 1);

	if (r < size)
	{
		// 2��и�
		if (c < size)
		{
			return Z(N - 1, r, c);
		}

		// 1��и�
		return size * size + Z(N - 1, r, c - size);
	}

	if (c < size)
	{
		// 3��и�
		return size * size * 2 + Z(N - 1, r - size, c);
	}

	// 4��и�
	return size * size * 3 + Z(N - 1, r - size, c - size);
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N, r, c;
	cin >> N >> r >> c;

	cout << Z(N, r, c) - 1 << "\n";
	
	return 0;
}