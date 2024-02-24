#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;

	while (T--)
	{
		int c, v;
		cin >> c >> v;

		printf("You get %d piece(s) and your dad gets %d piece(s).\n", c / v, c % v);
	}

	return 0;
}