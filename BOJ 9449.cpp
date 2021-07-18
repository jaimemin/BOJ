#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int W, H, w, h;
	cin >> W >> H >> w >> h;

	int result = ((W / w + 1) / 2) * ((H / h + 1) / 2);

	cout << result << "\n";

	return 0;
}