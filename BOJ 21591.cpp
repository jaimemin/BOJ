#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int wc, hc, ws, hs;
	cin >> wc >> hc >> ws >> hs;

	bool result = (wc - ws) >= 2 && (hc - hs) >= 2;

	cout << result << "\n";

	return 0;
}