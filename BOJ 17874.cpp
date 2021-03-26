#include <iostream>
#include <algorithm>
using namespace std;

const int HEIGHT = 4;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, h, v;
	cin >> n >> h >> v;

	int result = max({ h * v, h * (n - v), (n - h) * v, (n - h) * (n - v) }) * HEIGHT;

	cout << result << "\n";

	return 0;
}