#include <iostream>
using namespace std;

const int HAPPY = 10;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int S, M, L;
	cin >> S >> M >> L;

	int mood = S + 2 * M + 3 * L;

	cout << (mood >= HAPPY ? "happy\n" : "sad\n");

	return 0;
}