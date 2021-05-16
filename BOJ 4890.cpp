#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (1)
	{
		long long W, H;
		cin >> W >> H;

		if (W == 0 && H == 0)
		{
			break;
		}

		if (W < H)
		{
			swap(W, H);
		}

		if (W == H)
		{
			cout << 1 << "\n";

			continue;
		}

		if (W%H == 0)
		{
			cout << W / H << "\n";
		}
		else
		{
			cout << W * H << "\n";
		}
	}

	return 0;
}