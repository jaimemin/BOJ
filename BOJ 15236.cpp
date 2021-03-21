#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;

	int result = N * (N + 1) * (N + 2) / 2;

	cout << result << "\n";

	return 0;
}