#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string N;
	cin >> N;

	cout << (N.substr(0, 3) == "555" ? "YES" : "NO") << "\n";

	return 0;
}