#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;

	int headCnt = 0, tailCnt = 0;

	for (int i = 0; i < n; i++)
	{
		bool tail;
		cin >> tail;

		tail ? tailCnt++ : headCnt++;
	}

	int result = min(headCnt, tailCnt);

	cout << result << "\n";

	return 0;
}