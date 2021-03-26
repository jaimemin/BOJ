#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int A, B, C;
	cin >> A >> B >> C;

	int result = max({ A + B, B + C, C + A });

	cout << result << "\n";

	return 0;
}