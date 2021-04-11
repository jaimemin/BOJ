#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;

	int row = N / 2 + 1;
	int col = N - row + 2;
	int result = row * col;

	cout << result << "\n";

	return 0;
}