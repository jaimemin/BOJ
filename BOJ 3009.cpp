#include <iostream>
using namespace std;

const int MAX = 3;

typedef struct
{
	int x, y;
} Coord;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	Coord coordinates[MAX];

	for (int i = 0; i < MAX; i++)
	{
		cin >> coordinates[i].x >> coordinates[i].y;
	}

	int x, y;

	if (coordinates[0].x == coordinates[1].x)
	{
		x = coordinates[2].x;
	}
	else if (coordinates[0].x == coordinates[2].x)
	{
		x = coordinates[1].x;
	}
	else
	{
		x = coordinates[0].x;
	}

	if (coordinates[0].y == coordinates[1].y)
	{
		y = coordinates[2].y;
	}
	else if (coordinates[0].y == coordinates[2].y)
	{
		y = coordinates[1].y;
	}
	else
	{
		y = coordinates[0].y;
	}

	cout << x << " " << y << "\n";

	return 0;
}