#include <iostream>
#include <algorithm>
using namespace std;

int getSetCnt(int N, int cnt)
{
	return (N / cnt + (N % cnt != 0));
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N, A, B, C, D;
	cin >> N >> A >> B >> C >> D;

	int result = min(B * getSetCnt(N, A), D * getSetCnt(N, C));

	cout << result << "\n";

	return 0;
}