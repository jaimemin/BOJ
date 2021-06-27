#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int x, k, a;
	cin >> x >> k >> a;

	bool winner = k > (x % (k + a));

	cout << winner << "\n";

	return 0;
}