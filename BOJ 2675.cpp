#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	int T;
	cin >> T;

	while (T--)
	{
		int R;
		string S;
		cin >> R >> S;

		string output;

		for (char c : S)
		{
			for (int i = 0; i < R; i++)
			{
				output += c;
			}
		}

		cout << output << "\n";
	}

	return 0;
}