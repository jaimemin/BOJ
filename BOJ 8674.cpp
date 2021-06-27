#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	long long a, b;
	cin >> a >> b;

	if (a % 2 && b % 2)
	{
		cout << min(a, b) << "\n";
	}
	else
	{
		cout << 0 << "\n";
	}

	return 0;
}