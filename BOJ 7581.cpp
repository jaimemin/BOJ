#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (1)
	{
		int l, w, h, v;
		cin >> l >> w >> h >> v;

		if (l == 0 && w == 0 && h == 0 && v == 0)
		{
			break;
		}

		if (l == 0)
		{
			l = v / (w * h);
		}

		if (w == 0)
		{
			w = v / (l * h);
		}

		if (h == 0)
		{
			h = v / (l * w);
		}

		if (v == 0)
		{
			v = l * w * h;
		}

		cout << l << " " << w << " " << h << " " << v << "\n";
	}

	return 0;
}