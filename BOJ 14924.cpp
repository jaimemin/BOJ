#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int S, T, D;
	cin >> S >> T >> D;

	int meetingTime = D / (S * 2);
	int result = T * meetingTime;

	cout << result << "\n";

	return 0;
}