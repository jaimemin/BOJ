#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int A, B, C;
	cin >> A >> B >> C;

	int result = max(B - (A + 1), C - (B + 1));

	cout << result << "\n";

	return 0;
}