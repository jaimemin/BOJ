#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int l, r;
	cin >> l >> r;

	if (l == 0 && r == 0)
	{
		cout << "Not a moose\n";

		return 0;
	}

	if (l == r)
	{
		cout << "Even " << 2 * l << "\n";
	}
	else
	{
		cout << "Odd " << 2 * max(l, r) << "\n";
	}

	return 0;
}