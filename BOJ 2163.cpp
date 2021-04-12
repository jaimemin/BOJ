#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N, M;
	cin >> N >> M;

	int result = N * M - 1;

	cout << result << "\n";

	return 0;
}