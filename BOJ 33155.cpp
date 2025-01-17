#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 무한대 표기
const long long NEG_INF = -0x3f3f3f3f3f3f3f3fLL;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    long long K;
    cin >> N >> M >> K;

    vector<long long> A(N), V(N);

    for (int i = 0; i < N; i++) 
    {
        cin >> A[i];
    }

    vector<long long> B(M);

    for (int j = 0; j < M; j++) 
    {
        cin >> B[j];
    }

    for (int i = 0; i < N; i++) 
    {
        cin >> V[i];
    }

    // 궁합 C[i][j]
    vector<vector<long long>> C(N, vector<long long>(N, 0));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++) 
        {
            cin >> C[i][j];
        }
    }

    // ------------------------------------------------------------
    // 1) 바구니가 M > N 이면, 가장 큰 바구니 N개만 쓰면 됨 (굳이 M개 전부 안 써도 됨)
    //    -> B[] 내림차순 정렬 후 상위 N개만 slice
    if (M > N)
    {
        sort(B.begin(), B.end(), greater<long long>());
        B.resize(N);
        M = N;
    }
    else 
    {
        // M <= N인 경우엔 그냥 써도 됨. (괜찮으면 내림차순만 해둬도 됨)
        sort(B.begin(), B.end(), greater<long long>());
    }
    // 이제 B[0], B[1], ..., B[M-1] 를 사용할 예정 (M <= N)

    // ------------------------------------------------------------
    // 2) 부분집합 전처리: 각 subset s 에 대해,
    //    - sizeS[s] = sum(A_i)   (꽃 크기 합)
    //    - valueS[s] = sum(V_i)  (꽃 가치 합)
    //    - beautyS[s] = sum of C[i][j] (i<=j, i,j in s)
    //      (꽃 궁합 합, "아름다움")
    int fullMask = (1 << N);
    vector<long long> sizeS(fullMask, 0LL);
    vector<long long> valueS(fullMask, 0LL);
    vector<long long> beautyS(fullMask, 0LL);

    // 부분집합마다 A,V 합
    for (int s = 0; s < fullMask; s++)
    {
        long long sumA = 0, sumV = 0;

        for (int i = 0; i < N; i++) 
        {
            if (s & (1 << i))
            {
                sumA += A[i];
                sumV += V[i];
            }
        }

        sizeS[s] = sumA;
        valueS[s] = sumV;
    }

    // 부분집합마다 C 합(beauty)
    // N=15까지라, s=0..(1<<N)-1 에 대해 i,j 중첩(최대 15*15*2^15 = 450k 정도)이면 가능
    for (int s = 0; s < fullMask; s++) 
    {
        long long sumC = 0;
        // i <= j 인 모든 (i,j)에 대해, i,j가 s에 속하면 C[i][j] 더함
        // (아래처럼 간단 이중 for문으로 해도 되지만, 더 빠른 방법도 가능)
        for (int i = 0; i < N; i++) 
        {
            if (s & (1 << i)) 
            {
                for (int j = i; j < N; j++)
                {
                    if (s & (1 << j)) 
                    {
                        sumC += C[i][j];
                    }
                }
            }
        }

        beautyS[s] = sumC;
    }

    // ------------------------------------------------------------
    // 3) DP 배열: dp[state][i]
    //    state: (남은) 꽃들의 집합, i: 현재 바구니 인덱스 (0..M)
    //    크기 = 2^N x (M+1)
    static long long dp[1 << 15][16]; // N 최대 15, M <= N 이므로 (M+1) <= 16
    // base case: dp[state][M] = 0 (더 이상 바구니가 없으니 아무것도 담을 수 없음)
    // 나머지는 -∞로 초기화

    for (int s = 0; s < fullMask; s++) 
    {
        for (int i = 0; i <= M; i++)
        {
            dp[s][i] = NEG_INF;
        }

        dp[s][M] = 0;
    }

    // 바구니를 뒤에서부터 앞으로( i=M-1 down to 0 ) 채워나가는 Bottom-Up
    for (int i = M - 1; i >= 0; i--) 
    {
        for (int s = 0; s < fullMask; s++) 
        {
            // 1) 이 바구니(i)를 안 쓰는 경우
            long long ret = dp[s][i + 1];

            // 2) 이 바구니(i)를 쓰는 경우
            //    s의 부분집합 중 (sizeS[sub] <= B[i]) && (valueS[sub] <= K)인 sub를 골라 담고,
            //    남은 건 s ^ sub 로 바뀜
            //    얻는 아름다움은 beautyS[sub], 이후 dp[s^sub][ i+1 ]
            //    sub != 0 이어야 "하나 이상 꽃을 담았다"는 조건을 만족하지만,
            //    문제 설명에 따라 "해당 바구니를 전혀 안 쓰는" 것도 이미 1)에서 커버되므로
            //    여기선 sub=0을 굳이 제외할 필요가 없거나, 혹은 제외해도 됩니다.
            //    (다만 '빈 바구니'는 아름다움 기여=0이므로 사실상 위 1)와 동일)

            // s의 모든 부분집합 sub를 순회 -> O(2^|s|)
            // 단, |s|최대 15일 수 있으니 최악엔 2^15 = 32768.
            // s=0일 때는 부분집합 1개(0)뿐.
            // 전체 s에 대해 2^N x 2^N = 4^N = 4^15 ~ 1.07e9, 구현 최적화 필요.

            // 부분집합 열거 기법: 
            //   for(int sub = s; ; sub = (sub-1) & s) { ... if(sub==0) break; }
            // 
            // 또는 0부터 s까지 모든 mask 중 (mask & s) == mask 로 체크
            // 여기서는 일반적인 방법(sub = (sub-1) & s)을 사용


            // sub=0..(각종) 순회가 깔끔하도록 do-while 쓰는 패턴
            int sub = s;

            do 
            {
                // 조건 체크
                if (sizeS[sub] <= B[i] && valueS[sub] <= K) 
                {
                    long long candidate = beautyS[sub] + dp[s ^ sub][i + 1];

                    if (candidate > ret)
                    {
                        ret = candidate;
                    }
                }

                sub = (sub - 1) & s;
            } while (sub != s);

            dp[s][i] = ret;
        }
    }

    // 답: dp[(1<<N)-1][0]
    cout << dp[(1 << N) - 1][0] << "\n";

    return 0;
}