#include <iostream>
#include <algorithm>
using namespace std;

typedef struct
{
	long long x1, y1;
	long long x2, y2;
} Rectangle;

bool isOutOfBound(Rectangle r1, Rectangle r2)
{
	return (r1.x2 < r2.x1
		|| r2.x2 < r1.x1
		|| r2.y2 > r1.y1
		|| r1.y2 > r2.y1);
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	Rectangle r1, r2;
	cin >> r1.x1 >> r1.y1 >> r1.x2 >> r1.y2;
	cin >> r2.x1 >> r2.y1 >> r2.x2 >> r2.y2;

	if (isOutOfBound(r1, r2))
	{
		cout << 0 << "\n";

		return 0;
	}

	long long width = min(r1.x2, r2.x2) - max(r1.x1, r2.x1);
	long long height = max(r1.y2, r2.y2) - min(r1.y1, r2.y1);
	long long area = abs(width * height);

	cout << area << "\n";

	return 0;
}