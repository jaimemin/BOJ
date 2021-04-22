#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N, K;
	cin >> N >> K;

	int cnt = 0;

	for (int i = 1; i <= N; i++)
	{
		if (N % i == 0 && ++cnt == K)
		{
			cout << i << "\n";

			return 0;
		}
	}

	cout << 0 << "\n";

	return 0;
}