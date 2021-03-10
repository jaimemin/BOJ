#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int topBurger, middleBurger, bottomBurger, cola, cider;
	cin >> topBurger >> middleBurger >> bottomBurger >> cola >> cider;

	int result = min(topBurger, min(middleBurger, bottomBurger)) + min(cola, cider) - 50;

	cout << result << "\n";

	return 0;
}