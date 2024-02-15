#include <iostream>
#include <string>
using namespace std;

typedef struct
{
	int h;
	int m;
	int s;
} Time;

Time convertStringToTime(string s)
{
	return { stoi(s.substr(0, 2))
		, stoi(s.substr(3, 2))
		, stoi(s.substr(6, 2))};
}

string getTwoDigits(string s)
{
	return s.length() == 1 ? "0" + s : s;
}

string convertTimeToString(Time t)
{
	string hour = to_string(t.h);
	string minute = to_string(t.m);
	string second = to_string(t.s);

	return getTwoDigits(hour)
		+ ":"
		+ getTwoDigits(minute)
		+ ":"
		+ getTwoDigits(second);

}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string start, end;
	cin >> start >> end;

	Time from = convertStringToTime(start);
	Time to = convertStringToTime(end);

	int second = to.s - from.s;
	int minute = to.m - from.m;
	int hour = to.h - from.h;

	if (second < 0)
	{
		second += 60;
		minute--;
	}

	if (minute < 0)
	{
		minute += 60;
		hour--;
	}

	if (hour < 0)
	{
		hour += 24;
	}

	cout << convertTimeToString({ hour, minute, second }) << "\n";

	return 0;
}