#include <iostream>
using namespace std;

/**
 * 전역 변수 (또는 main 내부에서 static 사용)
 *  - N, K 최대 500,000까지 가능
 *  - Ai 최대 10^9까지 가능
 */
const int MAXN = 500000;

int N, K;

int A[MAXN];

/**
 * @brief
 *  X가 "최종 AND 값"으로 가능한지(즉, 모든 남은 원소들이 X의 모든 비트를 포함하도록 만들 수 있는지)
 *  그리디하게 검사하는 함수.
 *
 * @param X  후보로 검사할 정수
 * @return 가능하면 true, 불가능하면 false
 */
bool feasible(long long X) 
{
    long long aggregator = 0;
    int segmentCount = 0;      // 만들어진 세그먼트(유효 원소) 개수

    for (int i = 0; i < N; i++) 
    {
        aggregator |= A[i];
        // 현재까지의 OR이 X가 요구하는 모든 비트를 포함하면 세그먼트 1개 완성
        if ((aggregator & X) == X)
        {
            segmentCount++;

            aggregator = 0; // 다음 세그먼트를 위해 리셋
        }
    }

    // 세그먼트를 최대한 많이 만들었을 때 segmentCount = S
    // 병합 횟수 = N - S
    // "병합을 최대 K번까지 할 수 있다" = "S는 최소 (N-K) 이상이 되어야 한다."
    return (segmentCount >= (N - K));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> K;

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    long long answer = 0LL;

    // 최댓값 10^9 이므로 30비트(2^30=1073741824) 정도까지만 확인하면 충분
    // 31비트까지 써도 문제 없음
    for (int bit = 30; bit >= 0; bit--) 
    {
        long long testCandidate = answer | (1LL << bit);

        if (feasible(testCandidate))
        {
            answer = testCandidate;
        }
    }

    cout << answer << "\n";

    return 0;
}
