#include <iostream>
using namespace std;

const int MAX = 6;

int properChessPieces[MAX] = { 1, 1, 2, 2, 2, 8 };

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < MAX; i++)
	{
		int cnt;
		cin >> cnt;

		cout << properChessPieces[i] - cnt << " ";
	}
	cout << "\n";

	return 0;
}