#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int x, y, w, h;
	cin >> x >> y >> w >> h;

	int result = min({ x, w - x, y, h - y });

	cout << result << "\n";

	return 0;
}