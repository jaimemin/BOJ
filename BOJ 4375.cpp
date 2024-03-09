#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	int n;
	
	while (~scanf_s("%d", &n))
	{
		int copyN = n;
		int digit = 0;

		while (copyN)
		{
			digit++;

			copyN /= 10;
		}

		string s;

		for (int i = 0; i < digit; i++)
		{
			s += '1';
		}

		while (true)
		{
			long long num = stoll(s);

			if (num % n == 0)
			{
				cout << s.length() << "\n";

				break;
			}

			s += '1';
		}
	}

	return 0;
}