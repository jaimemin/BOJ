#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int A, B;
	cin >> A >> B;

	int result = max(A, B);

	cout << result << "\n";

	return 0;
}