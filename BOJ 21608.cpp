#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

const int MAX = 20;
const int FRIENDS_MAX = 4;
const int INF = 400 + 40;

typedef struct
{
	int y, x;
} Coord;

typedef struct
{
	int y, x;
} Dir;

Dir moveDir[MAX] = { {-1, 0}, {0, -1}, {0, 1}, {1, 0} };

int N;
int classRoom[MAX][MAX];
map<int, vector<int>> likeFriends;

bool doesContainLikeFriend(vector<int> friendList, int adjacentStudent)
{
	for (int i = 0; i < FRIENDS_MAX; i++)
	{
		if (friendList[i] == adjacentStudent)
		{
			return true;
		}
	}

	return false;
}

void placeStudent(int student)
{
	int likeFriendCnt = 0;
	int adjacentEmptySeatCnt = 0;
	Coord coord = { INF, INF };

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			if (classRoom[y][x])
			{
				continue;
			}

			int tempLikeFriendCnt = 0;
			int tempAdjacentEmptySeatCnt = 0;

			for (int k = 0; k < 4; k++)
			{
				int nextY = y + moveDir[k].y;
				int nextX = x + moveDir[k].x;

				if (nextY < 0 || nextY >= N || nextX < 0 || nextX >= N)
				{
					continue;
				}

				int adjacentStudent = classRoom[nextY][nextX];

				// 옆자리가 빈자리
				if (adjacentStudent == 0)
				{
					tempAdjacentEmptySeatCnt++;

					continue;
				}

				// 옆자리가 좋아하는 친구
				if (doesContainLikeFriend(likeFriends[student], adjacentStudent))
				{
					tempLikeFriendCnt++;
				}
			}

			// 첫 번째 조건: 좋아하는 학생이 인접한 칸에 가장 많은 칸
			if (tempLikeFriendCnt > likeFriendCnt)
			{
				likeFriendCnt = tempLikeFriendCnt;
				adjacentEmptySeatCnt = tempAdjacentEmptySeatCnt;
				coord = { y, x };

				continue;
			}

			// 두 번째 조건: 인접한 칸 중에서 비어있는 칸이 가장 많은 칸
			if (likeFriendCnt == tempLikeFriendCnt)
			{
				if (tempAdjacentEmptySeatCnt > adjacentEmptySeatCnt)
				{
					adjacentEmptySeatCnt = tempAdjacentEmptySeatCnt;
					coord = { y, x };

					continue;
				}

				// 세 번째 조건: 행의 번호가 가장 작은 칸, 행이 동일할 경우 열의 번호가 가장 작은 칸
				if (adjacentEmptySeatCnt == tempAdjacentEmptySeatCnt)
				{
					if (coord.y > y || (coord.y == y && coord.x > x))
					{
						coord = { y, x };
					}
				}
			}
		}
	}

	classRoom[coord.y][coord.x] = student;
}

int calculateSatisfaction(void)
{
	int satisfaction = 0;

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			int student = classRoom[y][x];
			vector<int> friends = likeFriends[student];
			int likeFriendCnt = 0;

			for (int k = 0; k < 4; k++)
			{
				int nextY = y + moveDir[k].y;
				int nextX = x + moveDir[k].x;

				if (nextY < 0 || nextY >= N || nextX < 0 || nextX >= N)
				{
					continue;
				}

				int adjacentStudent = classRoom[nextY][nextX];

				for (int likeFriend : friends)
				{
					if (likeFriend == adjacentStudent)
					{
						likeFriendCnt++;

						break;
					}
				}
			}

			switch (likeFriendCnt)
			{
			case 0:
				break;
			case 1:
				satisfaction += 1;

				break;
			case 2:
				satisfaction += 10;

				break;
			case 3:
				satisfaction += 100;

				break;
			case 4:
				satisfaction += 1000;

				break;
			}
		}
	}

	return satisfaction;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;

	vector<int> students(N*N);

	for (int i = 0; i < N*N; i++)
	{
		cin >> students[i];

		vector<int> friends(FRIENDS_MAX);

		for (int j = 0; j < FRIENDS_MAX; j++)
		{
			cin >> friends[j];
		}

		likeFriends[students[i]] = friends;
	}

	for (int i = 0; i < N*N; i++)
	{
		placeStudent(students[i]);
	}

	int result = calculateSatisfaction();

	cout << result << "\n";

	return 0;
}