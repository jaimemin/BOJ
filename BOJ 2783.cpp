#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	double X, Y;
	int N;
	cin >> X >> Y >> N;

	double costPerGram = X / Y;

	for (int i = 0; i < N; i++)
	{
		double cost, gram;
		cin >> cost >> gram;

		costPerGram = min(costPerGram, cost / gram);
	}

	printf("%.2lf\n", costPerGram * 1000);

	return 0;
}