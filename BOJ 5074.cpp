#include <iostream>
#include <string>
using namespace std;

const int MAX_MINUTE = 60;
const int MAX_HOUR = 24;

typedef struct
{
	int h, m;
} Time;

Time getTime(string s)
{
	return { stoi(s.substr(0, 2)), stoi(s.substr(3, 2)) };
}

void printResult(Time startTime, Time durationTime)
{
	int minute = startTime.m + durationTime.m;
	int hour = startTime.h + durationTime.h;

	if (minute >= MAX_MINUTE)
	{
		minute -= MAX_MINUTE;

		hour++;
	}

	int days = 0;

	while (hour >= MAX_HOUR)
	{
		hour -= MAX_HOUR;

		days++;
	}

	if (hour < 10)
	{
		cout << 0;
	}

	cout << hour << ":";

	if (minute < 10)
	{
		cout << 0;
	}

	cout << minute;

	if (days)
	{
		cout << " +" << days;
	}

	cout << "\n";
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (1)
	{
		string start, duration;
		cin >> start >> duration;

		if (start == "00:00" && duration == "00:00")
		{
			break;
		}

		Time startTime = getTime(start);
		Time durationTime = getTime(duration);

		printResult(startTime, durationTime);
	}

	return 0;
}