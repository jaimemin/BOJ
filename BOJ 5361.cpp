#include <iostream>
using namespace std;

const double BLASTER_RIFLE = 350.34;
const double VISUAL_SENSOR = 230.90;
const double AUDITORY_SENSOR = 190.55;
const double ARM = 125.30;
const double LEG = 180.90;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		int A, B, C, D, E;
		cin >> A >> B >> C >> D >> E;

		double result = A * BLASTER_RIFLE 
			+ B * VISUAL_SENSOR 
			+ C * AUDITORY_SENSOR 
			+ D * ARM 
			+ E * LEG;

		printf("$%.2lf\n", result);
	}

	return 0;
}