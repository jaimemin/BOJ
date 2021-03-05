#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n1, k1, n2, k2;
	cin >> n1 >> k1 >> n2 >> k2;

	int businessClassCnt = n1 * k1;
	int economyClassCnt = n2 * k2;
	int result = businessClassCnt + economyClassCnt;

	cout << result << "\n";

	return 0;
}