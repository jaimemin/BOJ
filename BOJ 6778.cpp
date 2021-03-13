#include <iostream>
using namespace std;

void printAlienNames(int antenna, int eyes)
{
	if (antenna >= 3 && eyes <= 4)
	{
		cout << "TroyMartian\n";
	}

	if (antenna <= 6 && eyes >= 2)
	{
		cout << "VladSaturnian\n";
	}

	if (antenna <= 2 && eyes <= 3)
	{
		cout << "GraemeMercurian\n";
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int antenna, eyes;
	cin >> antenna >> eyes;
	
	printAlienNames(antenna, eyes);

	return 0;
}