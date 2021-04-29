#include <iostream>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

const int MAX = 50;

typedef struct
{
	int m;
	int s;
	int d;
} FireBall;

typedef struct
{
	int y, x;
} Dir;

Dir moveDir[8] = { {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1} };

int N;
vector<pair<int, int>> fireBallLocations;
map<pair<int, int>, vector<FireBall>> coord2FireBalls;
map<pair<int, int>, vector<FireBall>> rightAfterFireBallMove;

int getAppropriateLocation(int loc)
{
	if (loc == -1)
	{
		return N - 1;
	}

	if (loc == N)
	{
		return 0;
	}

	return loc;
}

int getNextY(int y, int d)
{
	int nextY = y + moveDir[d].y;

	return getAppropriateLocation(nextY);
}

int getNextX(int x, int d)
{
	int nextX = x + moveDir[d].x;

	return getAppropriateLocation(nextX);
}

void moveFireBalls(void)
{
	for (pair<int, int> coord : fireBallLocations)
	{
		int y = coord.first;
		int x = coord.second;
		vector<FireBall> fireBalls = coord2FireBalls[{y, x}];
		
		for (FireBall fireBall : fireBalls) 
		{
			int nextY = y;
			int nextX = x;

			for (int k = 0; k < fireBall.s; k++)
			{
				nextY = getNextY(nextY, fireBall.d);
				nextX = getNextX(nextX, fireBall.d);
			}

			rightAfterFireBallMove[{nextY, nextX}].push_back(fireBall);
		}
	}

	fireBallLocations.clear();
	coord2FireBalls.clear();
}

void processFireballs(void)
{
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			vector<FireBall> fireBalls = rightAfterFireBallMove[{y, x}];

			if (fireBalls.empty())
			{
				continue;
			}

			if (fireBalls.size() == 1)
			{
				fireBallLocations.push_back({ y, x });
				coord2FireBalls[{y, x}].push_back(fireBalls[0]);

				continue;
			}

			bool isDirAllEven = true;
			bool isDirAllOdd = true;
			int totalMass = 0;
			int totalSpeed = 0;


			for (FireBall fireBall : fireBalls)
			{
				if (fireBall.d % 2)
				{
					isDirAllEven = false;
				}

				if (fireBall.d % 2 == 0)
				{
					isDirAllOdd = false;
				}

				totalMass += fireBall.m;
				totalSpeed += fireBall.s;
			}

			int mass = (int)floor(totalMass / 5);
			int speed = (int)floor(totalSpeed / fireBalls.size());

			if (mass == 0)
			{
				continue;
			}

			fireBallLocations.push_back({ y, x });

			for (int i = ((isDirAllOdd || isDirAllEven) ? 0 : 1); i < 8; i += 2)
			{
				FireBall fireBall = { mass, speed, i };

				coord2FireBalls[{y, x}].push_back(fireBall);
			}
		}
	}

	rightAfterFireBallMove.clear();
}

int getTotalMass(void)
{
	int result = 0;

	for (pair<int, int> coord : fireBallLocations)
	{
		vector<FireBall> fireBalls = coord2FireBalls[coord];

		for (FireBall fireBall : fireBalls)
		{
			result += fireBall.m;
		}
	}

	return result;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int M, K;
	cin >> N >> M >> K;

	for (int i = 0; i < M; i++)
	{
		int y, x;
		FireBall fireBall;
		cin >> y >> x >> fireBall.m >> fireBall.s >> fireBall.d;

		fireBallLocations.push_back({ y - 1, x - 1 });
		coord2FireBalls[{y - 1, x - 1}].push_back(fireBall);
	}

	for (int k = 0; k < K; k++)
	{
		moveFireBalls();	
		processFireballs();
	}

	int result = getTotalMass();

	cout << result << "\n";

	return 0;
}