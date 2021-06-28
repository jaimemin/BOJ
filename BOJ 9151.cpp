#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 151200;

int getCubic(int num)
{
	return num * num * num;
}

int getTetrahedral(int num)
{
	return (num * (num + 1) * (num + 2) / 6);
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (1)
	{
		int num;
		cin >> num;

		if (num == 0)
		{
			break;
		}

		int result = 0;

		for (int i = 1; ; i++)
		{
			if (getCubic(i) > num)
			{
				break;
			}

			result = max(result, getCubic(i));
		}

		for (int i = 1; ; i++)
		{
			if (getTetrahedral(i) > num)
			{
				break;
			}

			result = max(result, getTetrahedral(i));
		}

		for (int i = 1; getCubic(i) <= num; i++)
		{
			for (int j = 1; getTetrahedral(j) <= num; j++)
			{
				int temp = getCubic(i) + getTetrahedral(j);

				if (temp > num)
				{
					continue;
				}

				result = max(result, temp);
			}
		}

		cout << result << "\n";
	}

	return 0;
}