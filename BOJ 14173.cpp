#include <iostream>
#include <algorithm>
using namespace std;

typedef struct
{
	int x1, y1, x2, y2;
}Rectangle;

void getPastureInput(Rectangle &r)
{
	cin >> r.x1 >> r.y1 >> r.x2 >> r.y2;
}

int getMaxH(Rectangle r, Rectangle r2)
{
	return max(max(r.x2 - r.x1, r2.x2 - r2.x1)
		, max(r.x2 - r2.x1, r2.x2 - r.x1));
}

int getMaxR(Rectangle r, Rectangle r2)
{
	return max(max(r.y2 - r.y1, r2.y2 - r2.y1)
		, max(r.y2 - r2.y1, r2.y2 - r.y1));
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	Rectangle firstPasture, secondPasture;

	getPastureInput(firstPasture);
	getPastureInput(secondPasture);

	int h = getMaxH(firstPasture, secondPasture);
	int r = getMaxR(firstPasture, secondPasture);
	int side = max(h, r);
	int result = side * side;

	cout << result << "\n";

	return 0;
}