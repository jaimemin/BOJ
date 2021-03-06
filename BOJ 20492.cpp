#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;

	long long firstResult = (int)(N * 0.78);
	long long secondResult = N - (int)(N * 0.2 * 0.22);

	cout << firstResult << " " << secondResult << "\n";

	return 0;
}