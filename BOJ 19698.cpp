#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N, W, H, L;
	cin >> N >> W >> H >> L;

	int result = min((W / L) * (H / L), N);

	cout << result << "\n";

	return 0;
}