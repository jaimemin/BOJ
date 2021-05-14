#include <iostream>
#include <string>
using namespace std;

const int SECOND2MINUTE = 60;
const int MINUTE2HOUR = 60;
const int MAX_HOUR = 24;

typedef struct
{
	int h, m, s;
} Time;

Time getTime(string s)
{
	Time time = { stoi(s.substr(0, 2)), stoi(s.substr(3, 2)), stoi(s.substr(6, 2)) };

	return time;
}

void printResult(int h, int m, int s)
{
	if (h == 0 && m == 0 && s == 0)
	{
		cout << "24:00:00\n";

		return;
	}

	if (h < 10)
	{
		cout << "0";
	}

	cout << h << ":";

	if (m < 10)
	{
		cout << "0";
	}

	cout << m << ":";

	if (s < 10)
	{
		cout << "0";
	}

	cout << s << "\n";
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string currentTime, nateulyumTime;
	cin >> currentTime >> nateulyumTime;

	Time current = getTime(currentTime);
	Time nateulyum = getTime(nateulyumTime);

	int second = nateulyum.s - current.s;
	int minute = nateulyum.m - current.m;
	int hour = nateulyum.h - current.h;

	if (second < 0)
	{
		second += SECOND2MINUTE;

		minute--;
	}

	if (minute < 0)
	{
		minute += MINUTE2HOUR;

		hour--;
	}

	if (hour < 0)
	{
		hour += MAX_HOUR;
	}

	printResult(hour, minute, second);

	return 0;
}