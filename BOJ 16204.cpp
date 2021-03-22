#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N, M, K;
	cin >> N >> M >> K;

	int result = min(M, K) + min(N - M, N - K);

	cout << result << "\n";
	
	return 0;
}