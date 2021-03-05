#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;

	int result = n * (n + 1) / 2;

	cout << result << "\n";

	return 0;
}