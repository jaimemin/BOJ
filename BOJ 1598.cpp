#include <iostream>
#include <algorithm>
using namespace std;

const int MOD = 4;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int a, b;
	cin >> a >> b;

	a--, b--;

	int aX = a / MOD, aY = a % MOD;
	int bX = b / MOD, bY = b % MOD;

	int result = abs(aX - bX) + abs(aY - bY);

	cout << result << "\n";

	return 0;
}