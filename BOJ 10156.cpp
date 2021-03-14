#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int K, N, M;
	cin >> K >> N >> M;

	int result = max(K * N - M, 0);

	cout << result << "\n";

	return 0;
}