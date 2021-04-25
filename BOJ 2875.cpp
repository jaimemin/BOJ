#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N, M, K;
	cin >> N >> M >> K;

	int result = min({ N / 2, M, (N + M - K) / 3 });

	cout << result << "\n";

	return 0;
}