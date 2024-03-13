#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Time
{
	int minute;
	int second;
};

typedef struct
{
	int team;
	Time time;
} State;

Time convertStringToTime(string s)
{
	return { stoi(s.substr(0, 2)), stoi(s.substr(3, 2)) };
}

Time getSum(vector<Time>& v)
{
	if (v.size() % 2)
	{
		v.push_back({ 48, 0 });
	}

	Time sum = { 0, 0 };

	for (int i = 0; i < v.size(); i += 2)
	{
		Time start = v[i];
		Time end = v[i + 1];

		int second = end.second - start.second;
		int carry = 0;

		if (second < 0)
		{
			second += 60;
			carry += 1;
		}

		int minute = end.minute - start.minute - carry;
		sum.second += second;

		if (sum.second >= 60)
		{
			sum.second -= 60;
			sum.minute++;
		}

		sum.minute += minute;
	}

	return sum;
}

string printTime(Time t)
{
	return (t.minute < 10 ? "0" : "") + to_string(t.minute) + ":" + (t.second < 10 ? "0" : "") + to_string(t.second);
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;

	vector<State> v;
	int one = 0, two = 0;

	for (int i = 0; i < N; i++)
	{
		int team;
		string time;
		cin >> team >> time;

		v.push_back({ team, convertStringToTime(time) });
	}

	vector<Time> ones, twos;

	for (State state : v)
	{
		state.team == 1 ? one++ : two++;

		if (one - 1 > two)
		{
			continue;
		}

		if (two - 1 > one)
		{
			continue;
		}

		if (one > two && ones.size() % 2 == 0)
		{
			ones.push_back(state.time);
		}
		else if (one == two)
		{
			ones.size() % 2 ? ones.push_back(state.time) : twos.push_back(state.time);
		}
		else if (two > one && twos.size() % 2 == 0)
		{
			twos.push_back(state.time);
		}
	}

	Time oneSum = getSum(ones);
	Time twoSum = getSum(twos);

	cout << printTime(oneSum) << "\n" << printTime(twoSum) << "\n";

	return 0;
}