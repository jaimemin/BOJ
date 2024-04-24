#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 123456 + 123;

typedef struct
{
	int type;
	int attack;
	int health;
} Room;

long long N, A;

long long result;

Room rooms[MAX];

bool check(long long mid)
{
	long long hp = mid;
	long long attack = A;

	for (int i = 0; i < N; i++)
	{
		if (rooms[i].type == 1)
		{
			long long cnt = rooms[i].health / attack + (rooms[i].health % attack ? 1 : 0);
			hp -= (cnt - 1) * rooms[i].attack;
		}
		else
		{
			hp = min(mid, hp + rooms[i].health);
			attack += rooms[i].attack;
		}

		if (hp <= 0)
		{
			return false;
		}
	}

	return hp > 0;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> A;

	for (int i = 0; i < N; i++)
	{
		int t, a, h;
		cin >> t >> a >> h;

		rooms[i] = { t, a, h };
	}

	long long left = 1, right = 1e18;

	while (left <= right)
	{
		long long mid = (left + right) / 2;

		if (check(mid))
		{
			result = mid;

			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}

	cout << result << "\n";

	return 0;
}