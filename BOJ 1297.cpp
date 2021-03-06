#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int diagonal, heightRatio, widthRatio;
	cin >> diagonal >> heightRatio >> widthRatio;

	double x = sqrt((double)(diagonal * diagonal) / (heightRatio * heightRatio + widthRatio * widthRatio));
	int height = floor(heightRatio * x);
	int width = floor(widthRatio * x);

	cout << height << " " << width << "\n";

	return 0;
}