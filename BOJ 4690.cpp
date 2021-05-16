#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int a = 1; a <= 100; a++)
	{
		for (int b = 2; b <= a; b++)
		{
			for (int c = b; c <= a; c++)
			{
				for (int d = c; d <= a; d++)
				{
					if (a * a * a == b * b * b + c * c * c + d * d * d)
					{
						cout << "Cube = " << a << ", Triple = (" << b << "," << c << "," << d << ")\n";
					}
				}
			}
		}
	}

	return 0;
}