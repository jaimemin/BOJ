#include <iostream>
using namespace std;

bool gotAttacked(int time, int attack, int rest)
{
	return time % (attack + rest) <= attack && time % (attack + rest);
}

int getDogCnt(int time, int A, int B, int C, int D)
{
	return gotAttacked(time, A, B) + gotAttacked(time, C, D);
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int A, B, C, D;
	int P, M, N;
	cin >> A >> B >> C >> D >> P >> M >> N;

	cout << getDogCnt(P, A, B, C, D) << "\n";
	cout << getDogCnt(M, A, B, C, D) << "\n";
	cout << getDogCnt(N, A, B, C, D) << "\n";

	return 0;
}