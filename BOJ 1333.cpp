#include <iostream>
using namespace std;

const int SILENT_SECTION = 5;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N, L, D;
	cin >> N >> L >> D;

	int result;
	
	// 최악 케이스
	for(int i=1; ; i++)
	{
		if (D * i > N * L + (N - 1) * SILENT_SECTION)
		{
			result = D * i;

			break;
		}
	}

	for (int n = 1; n <= N; n++)
	{
		int silentStart = n * L + (n - 1) * SILENT_SECTION;
		int silentEnd = silentStart + SILENT_SECTION;

		bool foundAnswer = false;

		for (int i = 1; D * i < silentEnd; i++)
		{
			if (silentStart <= D * i && D * i < silentEnd)
			{
				result = D * i;
				foundAnswer = true;

				break;
			}

			// 동시에 끝날 경우 X
			if (silentStart < D * i + 1 && D * i + 1 < silentEnd)
			{
				result = D * i + 1;
				foundAnswer = true;

				break;
			}
		}

		if (foundAnswer)
		{
			break;
		}
	}

	cout << result << "\n";

	return 0;
}