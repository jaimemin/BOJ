#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int V;
	string s;
	cin >> V >> s;

	int A = 0;

	for (char c : s)
	{
		if (c == 'A')
		{
			A++;
		}
	}

	if (A > V - A)
	{
		cout << "A\n";
	}
	else if (A == V - A)
	{
		cout << "Tie\n";
	}
	else
	{
		cout << "B\n";
	}

	return 0;
}