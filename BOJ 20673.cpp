#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int p, q;
	cin >> p >> q;

	if (50 >= p && 10 >= q)
	{
		cout << "White\n";
	}
	else if (30 <= q)
	{
		cout << "Red\n";
	}
	else
	{
		cout << "Yellow\n";
	}

	return 0;
}