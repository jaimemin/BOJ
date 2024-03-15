#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	int num = 666;

	while (true)
	{
		if (to_string(num).find("666") != string::npos)
		{
			if (--N == 0)
			{
				cout << num << "\n";

				return 0;
			}
		}

		num++;
	}
}