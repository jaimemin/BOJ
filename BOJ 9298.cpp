#include <iostream>
#include <algorithm>
using namespace std;

const double MAX = 1001;
const double MIN = -1001;

int main(void)
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++)
	{
		int N;
		cin >> N;

		double minX = MAX, maxX = MIN;
		double minY = MAX, maxY = MIN;

		for (int n = 0; n < N; n++)
		{
			double X, Y;
			cin >> X >> Y;

			minX = min(minX, X);
			maxX = max(maxX, X);
			minY = min(minY, Y);
			maxY = max(maxY, Y);
		}

		printf("Case %d: ", t);

		double area = abs((maxX - minX) * (maxY - minY));
		double perimeter = abs((maxX - minX) + (maxY - minY)) * 2;

		printf("Area %.9lf, Perimeter %.9lf\n", area, perimeter);
	}

	return 0;
}