#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAX_CLOUD_LENGTH = 2;
const int MAX = 50;

typedef struct
{
	int y, x;
} Coord;

typedef struct
{
	int y, x;
} Dir;

Dir moveDir[9] = { {0, 0}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1} };

int N;
int A[MAX][MAX];
bool visited[MAX][MAX];
vector<Coord> clouds;

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

void createInitialClouds(void)
{
	clouds.push_back({ N - 1, 0 });
	clouds.push_back({ N - 1, 1 });
	clouds.push_back({ N - 2, 0 });
	clouds.push_back({ N - 2, 1 });
}

void moveClouds(int d, int s)
{
	vector<Coord> tempClouds = clouds;
	// 3. 구름이 모두 사라진다
	clouds.clear();

	// 2. 각 구름에서 비가 내려 구름이 있는 칸의 바구니에
	// 저장된 물의 양이 1 증가한다.
	for (Coord coord : tempClouds)
	{
		int y = coord.y;
		int x = coord.x;

		for (int i = 0; i < s; i++)
		{
			y = getNextY(y, d);
			x = getNextX(x, d);
		}

		A[y][x]++;
		clouds.push_back({ y, x });
		visited[y][x] = true;
	}
}

void waterCopyMagic(void)
{
	for(Coord coord : clouds) 
	{
		int y = coord.y;
		int x = coord.x;
		int hasWaterCnt = 0;

		for (int k = 2; k <= 8; k+=2)
		{
			int nextY = y + moveDir[k].y;
			int nextX = x + moveDir[k].x;

			if (nextY < 0 || nextY >= N || nextX < 0 || nextX >= N)
			{
				continue;
			}

			if (A[nextY][nextX])
			{
				hasWaterCnt++;
			}
		}

		A[y][x] += hasWaterCnt;
	}

	clouds.clear();
}

void createNewCloud(void)
{
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			if (visited[y][x] || A[y][x] < 2)
			{
				continue;
			}

			clouds.push_back({ y, x });
			A[y][x] -= 2;
		}
	}
}

int getTotalWater(void)
{
	int result = 0;

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			result += A[y][x];
		}
	}

	return result;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int M;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> A[i][j];
		}
	}

	// 초기 구름 생성
	createInitialClouds();

	for (int m = 0; m < M; m++)
	{
		int d, s;
		cin >> d >> s;

		// 1. 모든 구름이 di 방향으로 si 칸 이동한다.
		moveClouds(d, s);
		// 4. 물복사
		waterCopyMagic();
		// 5. 신규 구름 생성
		createNewCloud();

		memset(visited, false, sizeof(visited));
	}

	int result = getTotalWater();

	cout << result << "\n";

	return 0;
}