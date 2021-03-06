#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	long long N, M;
	cin >> N >> M;
	
	cout << abs(N - M) << "\n";

	return 0;
}