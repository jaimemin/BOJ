#include <iostream>
#include <algorithm>
using namespace std;

const int QUOTA = 60;
const int QUOTA_PRICE = 1500;
const int EXTRA_PRICE = 3000;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;

	int result = min(n, QUOTA + k) * QUOTA_PRICE + max(n - k - QUOTA, 0) * EXTRA_PRICE;

	cout << result << "\n";

	return 0;
}