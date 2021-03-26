#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int X, L, R;
	cin >> X >> L >> R;

	if (X <= L)
	{
		cout << L << "\n";
	}
	else if (X >= R)
	{
		cout << R << "\n";
	}
	else
	{
		cout << X << "\n";
	}

	return 0;
}