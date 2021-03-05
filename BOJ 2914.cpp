#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int A, I;
	cin >> A >> I;

	// 올림이므로 평균이 (I - 1)이 되는 멜로디 갯수보다 1 더해주면 됨
	int result = A * (I - 1) + 1;

	cout << result << "\n";

	return 0;
}
