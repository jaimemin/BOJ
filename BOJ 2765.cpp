#include <iostream>
#include <iomanip>
using namespace std;

const double PI = 3.1415927;
const int INCH2MILE = 63360;
const int SECOND2HOUR = 3600;

double getDistance(double diameter, int rotateNum)
{
	double result = diameter / INCH2MILE * PI * rotateNum;

	return result;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 1; ; i++)
	{
		double diameter, second;
		int rotation;
		cin >> diameter >> rotation >> second;
		
		if (rotation == 0) 
		{
			break;
		}

		double distance = getDistance(diameter, rotation);
		double milesPerHour = distance / (second / SECOND2HOUR);

		cout << fixed << setprecision(2) << "Trip #" << i << ": " << distance << ' ' << milesPerHour << '\n';
	}

	return 0;
}