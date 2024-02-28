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
		int V, E;
		cin >> V >> E;

		cout << 2 - V + E << "\n";
	}

	return 0;
}