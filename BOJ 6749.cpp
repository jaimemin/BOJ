#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	int Y, M;
	cin >> Y >> M;

	int diff = M - Y;
	int oldestAge = M + diff;

	cout << oldestAge << "\n";

	return 0;
}