#include <iostream>
#include <string>
using namespace std;

const int MAX_SEAT = 68;
const int MIN_SEAT = 0;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (1)
	{
		string airline;
		int bookedCnt;
		cin >> airline >> bookedCnt;

		if (airline == "#" && bookedCnt == 0)
		{
			break;
		}

		while (1)
		{
			char op;
			int cnt;
			cin >> op >> cnt;

			if (op == 'X' && cnt == 0)
			{
				break;
			}

			if (op == 'B')
			{
				if (bookedCnt + cnt > MAX_SEAT)
				{
					continue;
				}

				bookedCnt += cnt;
			}
			else
			{
				if (bookedCnt - cnt < MIN_SEAT)
				{
					continue;
				}

				bookedCnt -= cnt;
			}
		}

		cout << airline << " " << bookedCnt << "\n";
	}

	return 0;
}