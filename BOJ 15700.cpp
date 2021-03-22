#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	long long N, M;
	cin >> N >> M;

	long long result = N * M / 2;

	cout << result << "\n";

	return 0;
}