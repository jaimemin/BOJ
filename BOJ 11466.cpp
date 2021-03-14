#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	double h, w;
	cin >> h >> w;

	if (w > h)
	{
		swap(w, h);
	}

	// 높이가 폭보다 3배 이상 클 경우
	if (h >= 3 * w)
	{
		printf("%.4lf\n", w);
	}
	else if (10 * h >= 15 * w)
	{
		// 높이가 폭보다 1.5배 크고 3배 미만일 때
		printf("%.4lf\n", h / 3);
	}
	else
	{
		// 높이가 폭의 1.5배 미만일 때
		printf("%.4lf\n", w / 2);
	}

	return 0;
}