#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int A, B, C;
	cin >> A >> B >> C;

	int maxCandy = max({ A, B, C });

	int result = (maxCandy - A) + (maxCandy - B) + (maxCandy - C);

	cout << result << "\n";
	
	return 0;
}