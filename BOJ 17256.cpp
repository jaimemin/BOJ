#include <iostream>
using namespace std;

typedef struct
{
	int x, y, z;
} Cake;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	Cake A, C;
	cin >> A.x >> A.y >> A.z;
	cin >> C.x >> C.y >> C.z;

	Cake B = { C.x - A.z, C.y / A.y, C.z - A.x };

	cout << B.x << " " << B.y << " " << B.z << "\n";

	return 0;
}