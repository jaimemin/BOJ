#include <iostream>
using namespace std;

const int UNIVERSITY_OPENING_YEAR = 1946;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;

	cout << N - UNIVERSITY_OPENING_YEAR << "\n";

	return 0;
}