#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
    문제 개요:
    - N개의 도시가 있고, 각 도시 i에는 A[i] 인구가 있다.
    - 각 사람은 반드시 X 또는 Y 중 하나에게만 투표한다(기권/무효표 없음).
    - 수연이 방식: 전체 득표수를 합산하여 더 많이 득표한 후보가 승리.
    - 현빈이 방식: 도시별 득표수를 비교하여, 더 많은 표를 얻은 후보가 그 도시를 "이긴다".
                    그리고 "이긴 도시의 개수"가 더 많은 후보가 승리.
    - "수연이 방식(X 승), 현빈이 방식(Y 승)"을 동시에 만족하는 표 분배가 가능한지 판별하고,
      가능하면 "YES" 및 표 분배 예시(X, Y 배열)을 출력, 불가능하면 "NO" 출력.

    본 코드는:
    1. n <= 2 인 경우: 무조건 NO (문제에서 원하는 상황 만족 불가)
    2. n >= 3 인 경우:
       - 일단 A를 "도시 인구 (p), 인덱스" 형태로 정렬한다.
       - 앞쪽(인구가 작은 도시들) 중 "n//2 + 1"개는 Y가 조금 더 많도록 배분
         (Y[idx] = p//2 + 1, X[idx] = p - Y[idx])
       - 나머지 도시들은 X가 전부 가져감 (X[idx] = p, Y[idx] = 0)
       - 이 때의 총합 sx, sy를 비교
         * 만약 sx > sy 라면 수연이 방식(X승) 달성 -> YES, 표 출력
         * 그렇지 않다면, n이 짝수일 때(도시 개수가 짝수) 시도해볼 수 있는 '미세 조정'을 수행
           - 인구가 작은 도시들 중에서 짝수이면서 p >= 2인 도시에서
             Y[idx]를 1 줄이고, X[idx]를 1 늘리는 식으로 재분배 후
             sx, sy 다시 계산 -> 만약 sx > sy가 되면 YES 출력
         * 그래도 sx <= sy 이면 NO.

    주의:
    - 이 로직은 문제에서 "정답이 존재하면 YES, 아니면 NO" 형태로 구현한 하나의 솔루션.
    - 문제에서 요구하는 "수연이(X승), 현빈이(Y승)" 분배를 찾는 여러 방법 중 하나에 해당.
    - 필요에 따라 조정된 방식이지만, 문제의 조건(동률 불허 등)을 만족하려고 노력한 로직.

    시간복잡도:
    - 각 테스트 케이스마다 O(N log N) 정렬.
    - T개 테스트, N의 총합 <= 1e6 규모에서 충분히 처리 가능.
*/

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t; // 테스트 케이스 개수

    while (t--)
    {
        int n;
        cin >> n; // 도시 개수

        vector<long long> A(n);

        for (int i = 0; i < n; i++) 
        {
            cin >> A[i];
        }

        // n <= 2인 경우: "X가 전체표에서 이기고, Y가 도시 수에서 이기는" 상황 불가능
        if (n <= 2) 
        {
            cout << "NO\n";

            continue;
        }

        // arr: (인구 p, 원래 인덱스 idx) 쌍을 만들어 정렬 (인구 오름차순)
        vector<pair<long long, int>> arr;
        arr.reserve(n);

        for (int i = 0; i < n; i++) 
        {
            arr.push_back({ A[i], i });
        }

        sort(arr.begin(), arr.end(), [](auto& a, auto& b) 
            { 
                return a.first < b.first; 
            }
        );

        // X, Y : 도시별 득표수 결과
        // 처음에는 모두 0으로 초기화
        vector<long long> X(n, 0), Y(n, 0);

        // need = n//2 + 1
        //  -> 인구가 작은 도시들 중 절반+1 개 정도에 대해 "Y가 조금 더 많이" 가져가도록 설정
        int need = n / 2 + 1;

        // 1) 앞쪽의 need개 도시 처리
        //    Y[idx] = p//2 + 1, X[idx] = p - Y[idx]
        //    -> Y가 해당 도시를 이기도록 (단, 동률 불가)
        for (int i = 0; i < need; i++)
        {
            long long p = arr[i].first;
            int idx = arr[i].second;
            // Y를 p//2+1 표로 설정 (가능하면 절반보다 1 크도록)
            Y[idx] = p / 2 + 1;
            X[idx] = p - Y[idx];
        }

        // 2) 나머지 도시들은 X가 전부 표를 가져감
        //    Y[idx] = 0
        for (int i = need; i < n; i++)
        {
            long long p = arr[i].first;
            int idx = arr[i].second;
            X[idx] = p;
            Y[idx] = 0;
        }

        // 이제 전체 득표수 sx, sy 계산
        long long sx = 0, sy = 0;

        for (int i = 0; i < n; i++) 
        {
            sx += X[i];
            sy += Y[i];
        }

        // 만약 sx > sy 이면 이미 "수연이 방식(X승)" 달성
        // 그리고 앞쪽 need개는 Y가 더 많으므로 대부분 도시에서 Y 승리 -> 현빈이 방식(Y승) 가능성
        // (단, 일부 도시가 동률이 아닌지 문제에서 주의 필요. 여기서는 동률 없도록 설계했음)
        if (sx > sy)
        {
            cout << "YES\n";
            // X 배열 출력
            for (int i = 0; i < n; i++)
            {
                cout << X[i] << (i + 1 < n ? ' ' : '\n');
            }
            // Y 배열 출력
            for (int i = 0; i < n; i++) 
            {
                cout << Y[i] << (i + 1 < n ? ' ' : '\n');
            }

            continue; // 다음 테스트 케이스로
        }

        // 여기까지 왔다면 sx <= sy 상태.
        // n이 짝수일 때, 미세 조정을 시도해볼 수 있다.
        bool tied = false;

        if (n % 2 == 0) 
        {
            // 앞쪽 need개 도시(= "Y가 더 많도록" 했던 도시) 중에서
            // 짝수이며 p >= 2인 도시를 찾아
            // Y[idx]를 1 줄이고, X[idx]를 1 늘려본다.
            // 그 후 sx > sy인지 확인 -> 되면 YES
            for (int i = 0; i < need; i++) 
            {
                long long p = arr[i].first;
                int idx = arr[i].second;

                if (p % 2 == 0 && p >= 2)
                {
                    // 일단 분배를 1 변경
                    Y[idx] -= 1;
                    X[idx] += 1;

                    // 다시 합산
                    long long newSx = 0, newSy = 0;

                    for (int j = 0; j < n; j++) 
                    {
                        newSx += X[j];
                        newSy += Y[j];
                    }

                    // 확인
                    if (newSx > newSy)
                    {
                        cout << "YES\n";
                        // 출력
                        for (int j = 0; j < n; j++) 
                        {
                            cout << X[j] << (j + 1 < n ? ' ' : '\n');
                        }

                        for (int j = 0; j < n; j++)
                        {
                            cout << Y[j] << (j + 1 < n ? ' ' : '\n');
                        }

                        tied = true;
                    }

                    if (!tied) 
                    {
                        // 다시 원복
                        X[idx] -= 1;
                        Y[idx] += 1;
                    }

                    // 만약 tied==true(즉 sx>sy 만족)되면 반복 종료
                    if (tied)
                    {
                        break;
                    }
                }
            }
        }

        // 만약 sx>sy 만족 못 시켰다면 NO
        if (!tied) 
        {
            cout << "NO\n";
        }
    }

    return 0;
}