#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;

	while (T--)
	{
		int yonsei = 0, korea = 0;
		
		for (int i = 0; i < 9; i++)
		{
			int a, b;
			cin >> a >> b;

			yonsei += a;
			korea += b;
		}

		if (yonsei > korea)
		{
			cout << "Yonsei\n";
		}
		else if (korea > yonsei)
		{
			cout << "Korea\n";
		}
		else
		{
			cout << "Draw\n";
		}
	}

	return 0;
}