#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		string input;
		cin >> input;

		int idx = input.find(',');
		int A = stoi(input.substr(0, idx));
		int B = stoi(input.substr(idx + 1));

		cout << A + B << "\n";
	}

	return 0;
}