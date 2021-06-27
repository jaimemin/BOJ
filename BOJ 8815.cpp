#include <iostream>
using namespace std;

const int MAX = 12;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int Z;
	cin >> Z;

	char result[MAX] = { 'A', 'B', 'C', 'B', 'C', 'D', 'C', 'D', 'A', 'D', 'A', 'B' };

	for (int z = 0; z < Z; z++)
	{
		int N;
		cin >> N;

		cout << result[(N - 1) % MAX] << "\n";
	}

	return 0;
}