#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int MAX = 3;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string operations;
	cin >> operations;

	bool cups[MAX] = { false, };
	cups[0] = true;

	for (int i = 0; i < operations.length(); i++)
	{
		switch (operations[i])
		{
		case 'A':
			swap(cups[0], cups[1]);

			break;
		case 'B':
			swap(cups[1], cups[2]);

			break;
		case 'C':
			swap(cups[0], cups[2]);

			break;
		}
	}

	for (int i = 0; i < MAX; i++)
	{
		if (cups[i])
		{
			cout << i + 1 << "\n";

			break;
		}
	}

	return 0;
}