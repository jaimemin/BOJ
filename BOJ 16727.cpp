#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int p1, s1, p2, s2;
	cin >> p1 >> s1 >> s2 >> p2;

	int diff = (p1 + p2) - (s1 + s2);

	if (diff > 0)
	{
		cout << "Persepolis\n";
	}
	else if (diff < 0)
	{
		cout << "Esteghlal\n";
	}
	else
	{
		if (s1 > p2)
		{
			cout << "Esteghlal\n";
		}
		else if (s1 < p2)
		{
			cout << "Persepolis\n";
		}
		else
		{
			cout << "Penalty\n";
		}
	}

	return 0;
}