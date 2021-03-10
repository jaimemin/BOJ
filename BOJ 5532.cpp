#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int L, A, B, C, D;
	cin >> L >> A >> B >> C >> D;

	int languageDay = (A / C) + (A % C != 0);
	int mathDay = (B / D) + (B % D != 0);

	cout << L - max(mathDay, languageDay) << "\n";

	return 0;
}