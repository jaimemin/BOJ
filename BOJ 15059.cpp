#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int Ca, Ba, Pa;
	cin >> Ca >> Ba >> Pa;

	int Cr, Br, Pr;
	cin >> Cr >> Br >> Pr;

	int result = (Ca - Cr < 0 ? abs(Ca - Cr) : 0)
		+ (Ba - Br < 0 ? abs(Ba - Br) : 0)
		+ (Pa - Pr < 0 ? abs(Pa - Pr) : 0);

	cout << result << "\n";

	return 0;
}