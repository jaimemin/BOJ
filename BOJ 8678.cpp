#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int Z;
	cin >> Z;

	for (int z = 0; z < Z; z++)
	{
		int a, b;
		cin >> a >> b;

		cout << (b%a ? "NIE\n" : "TAK\n");
	}

	return 0;
}