#include <iostream>
using namespace std;

const int MAX = 5;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int L, P;
	cin >> L >> P;

	int actualPeopleCnt = L * P;

	for (int i = 0; i < MAX; i++)
	{
		int peopleCnt;
		cin >> peopleCnt;

		cout << peopleCnt - actualPeopleCnt << " ";
	}
	cout << "\n";

	return 0;
}