#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int A, B, C, D;
	cin >> A >> B >> C >> D;

	int result = min(A + D, B + C);

	cout << result << "\n";

	return 0;
}