#include <iostream>
#include <string>
using namespace std;

const int MAX = 25;
const int START_YEAR = 1995;

string winners[MAX] = { "ITMO", "SPbSU", "SPbSU"
, "ITMO", "ITMO", "SPbSU"
, "ITMO", "ITMO", "ITMO"
, "ITMO", "ITMO", "PetrSU, ITMO"
, "SPbSU", "SPbSU", "ITMO"
, "ITMO", "ITMO", "ITMO"
, "SPbSU", "ITMO",  "ITMO"
, "ITMO", "ITMO", "SPbSU", "ITMO" };

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int y;
	cin >> y;

	cout << winners[y - START_YEAR] << "\n";

	return 0;
}