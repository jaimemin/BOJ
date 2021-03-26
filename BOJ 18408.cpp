#include <iostream>
using namespace std;

const int MAX = 3;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int oneCnt = 0, twoCnt = 0;

	for (int i = 0; i < MAX; i++)
	{
		int num;
		cin >> num;

		num == 1 ? oneCnt++ : twoCnt++;
	}

	cout << (oneCnt > twoCnt ? "1\n" : "2\n");

	return 0;
}