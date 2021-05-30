#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, p, h;
	cin >> n >> p >> h;

	for (int i = 0; i < n; i++)
	{
		int dollar;
		cin >> dollar;

		if (dollar > h)
		{
			printf("BBTV: Dollar reached %d Oshloobs, A record!\n", dollar);

			h = dollar;
			p = dollar;

			continue;
		}

		if (dollar < p)
		{
			printf("NTV: Dollar dropped by %d Oshloobs\n", p - dollar);
		}

		p = dollar;
	}

	return 0;
}