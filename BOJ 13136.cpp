#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	long long R, C, N;
	cin >> R >> C >> N;

	long long row = R / N + (R%N ? 1 : 0);
	long long col = C / N + (C%N ? 1 : 0);
	long long result = row * col * 1LL;

	cout << result << "\n";

	return 0;
}