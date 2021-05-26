#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	double H, P;

	while (~scanf("%lf %lf", &H, &P))
	{
		printf("%.2lf\n", H / P);
	}

	return 0;
}