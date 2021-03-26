#include <iostream>
using namespace std;

const int SATISFACTORY = 8;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int m, n;
	cin >> m >> n;

	cout << (m >= SATISFACTORY ? "satisfactory\n" : "unsatisfactory\n");

	return 0;
}