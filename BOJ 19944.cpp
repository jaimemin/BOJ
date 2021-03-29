#include <iostream>
using namespace std;

const int NEWBIE = 2;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N, M;
	cin >> N >> M;

	if (M <= NEWBIE)
	{
		cout << "NEWBIE!\n";
	}
	else if (M <= N)
	{
		cout << "OLDBIE!\n";
	}
	else
	{
		cout << "TLE!\n";
	}

	return 0;
}