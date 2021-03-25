#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

const int WEEK = 7;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int A, B, C;
	cin >> A >> B >> C;

	int weeklyScore = WEEK * A + B;
	int result = C / weeklyScore * WEEK + min((int)ceil((double)(C % weeklyScore) / (double)A), WEEK);

	cout << result << "\n";

	return 0;
}