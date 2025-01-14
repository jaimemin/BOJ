#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

/*
  주어진 multiset M(크기 N^2)로부터
  수열 A(길이 N, 양의 정수)를 복원하는 코드 예시.
*/

// 오버플로우 방지하며 곱셈하는 함수 (최대 10^18 범위 확인)
bool safeMultiplyCheck(long long a, long long b, long long& res) 
{
    if (a > 0 && b > LLONG_MAX / a)
    {
        return false;
    }

    res = a * b;

    return true;
}

// 제곱수 판정 및 제곱근 정수 구하기
// x 가 완전제곱이면 sqrt(x) (양의 정수), 아니면 -1 리턴
long long perfectSquareRoot(long long x)
{
    if (x < 0)
    {
        return -1;
    }

    long long r = (long long)floorl(sqrtl((long double)x));

    if ((long long)r * r == x)
    {
        return r;
    }

    if ((long long)(r + 1) * (r + 1) == x)
    {
        return r + 1;
    }

    return -1;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;

    vector<long long> M(N * N);

    for (int i = 0; i < N * N; i++)
    {
        cin >> M[i];
    }

    sort(M.begin(), M.end());

    // 특수 케이스: N=1
    if (N == 1)
    {
        // M[0] = A1*A1
        // A1 = sqrt(M[0]) 이 정수여야 가능
        long long s = perfectSquareRoot(M[0]);

        if (s > 0) 
        {
            cout << "YES\n" << s << "\n";
        }
        else 
        {
            cout << "NO\n";
        }

        return 0;
    }

    // 가장 작은 값 M[0]은 A1^2 이어야 함
    long long sq = M[0];
    long long A1 = perfectSquareRoot(sq);

    if (A1 <= 0) 
    {
        // 완전제곱 아님
        cout << "NO\n";

        return 0;
    }

    // multiset(또는 map)으로 빈도 관리
    // (중복이 많을 수 있으므로, long long -> long long 형태의 map 사용)
    unordered_map<long long, long long> freq; // 해시맵
    freq.reserve(N * N * 2ULL);
    freq.max_load_factor(0.7f);

    for (auto& x : M)
    {
        freq[x]++;
    }

    // A[1] = A1 확정 → M에서 (A1^2) 하나 제거
    // (i,i)인 곱은 1개만 있으므로 1만 제거
    if (freq[sq] < 1)
    {
        cout << "NO\n";

        return 0;
    }

    freq[sq]--;

    if (freq[sq] == 0)
    {
        freq.erase(sq);
    }

    vector<long long> A;
    A.push_back(A1);

    // 이제 A2 ~ AN을 차례대로 찾기
    for (int i = 2; i <= N; i++)
    {
        if (i == 2) {
            // 아직 A에는 A1 한 개만 있음
            // freq에서 "아직 제거되지 않은 가장 작은 product"를 고름
            // 그것이 A1 * A2 라고 가정 => A2 = (그 product)/A1
            // 만약 그 product가 A1로 나누어떨어지지 않으면 NO
            // (이 과정을 일반화해서 i=2 ~ N까지 동일하게 처리)
        }

        // freq가 비어있으면 모순
        if (freq.empty())
        {
            cout << "NO\n";

            return 0;
        }
        // 현재 freq에서 가장 작은 key를 찾기 위해:  
        //   1) unordered_map은 "가장 작은 key"를 효율적으로 꺼내기 어려움
        //   2) 매번 다시 정렬/우선순위큐를 만들면 비효율 (최악엔 가능)
        // 여기서는 map<long long,long long> (balanced tree)나
        // multiset<long long> 등을 쓰면 간단.
        // 예시 코드에서는 편의상 매번 선형 탐색해도 N=1000, N^2=10^6이면
        // 최적화에 따라 시간 내 가능할 수 있지만, 다소 위험할 수 있음.
        // 실 구현시에는 std::map<long long,long long>를 권장.

        // 여기서는 데모를 위해 "가장 작은 key"를 찾기 위해 일단 선형 탐색:
        long long smallestKey = LLONG_MAX;

        for (auto& p : freq)
        {
            if (p.first < smallestKey)
            {
                smallestKey = p.first;
            }
        }

        // smallestKey = A1 * A_i  라고 가정
        // => A_i = smallestKey / A1
        if (smallestKey % A1 != 0) 
        {
            // 나누어떨어지지 않으면 불가능
            cout << "NO\n";

            return 0;
        }

        long long Ai = smallestKey / A1;

        if (Ai <= 0)
        {
            // 양의 정수가 아님
            cout << "NO\n";

            return 0;
        }

        // 이제 A_i를 찾았으니, freq에서
        //   (A_i * A_j) (j=1..i)를 정확한 횟수만큼 제거해야 함
        // j=i 인 경우는 1번 (A_i^2)
        // j< i 인 경우는 2번 (A_j*A_i 와 A_i*A_j)
        // 이미 A = [A1, A2, ..., A_(i-1)] 가 있다고 치면
        // A_i^2 1개 + sum_{j=1 to i-1} 2개씩 제거

        // 임시로 A_i 추가하기
        A.push_back(Ai);

        // 제거해야 하는 곱들을 순회하면서 freq에서 감소
        //   - A_k: k=1..i
        //   - product = A_k * A_i
        //   - 필요 제거 횟수: 2 (k < i), 1 (k = i)
        // 주의: 곱이 10^18 넘어가는지 오버플로 체크
        for (int k = 1; k <= i; k++) 
        {
            long long mulVal;
            // A[k-1] == A_k  (벡터 인덱스는 k-1)
            long long ak = A[k - 1];

            if (!safeMultiplyCheck(ak, Ai, mulVal))
            {
                // 오버플로 => 실제로는 M에 들어갈 수 없는 곱
                cout << "NO\n";

                return 0;
            }

            long long needCount = (k == i ? 1LL : 2LL);

            // freq[mulVal]에서 needCount만큼 빼야 함
            if (freq.find(mulVal) == freq.end() || freq[mulVal] < needCount)
            {
                // 제거 불가
                cout << "NO\n";

                return 0;
            }

            freq[mulVal] -= needCount;

            if (freq[mulVal] == 0) 
            {
                freq.erase(mulVal);
            }
        }
    }

    // 여기까지 왔다면 A를 성공적으로 구함
    if ((int)A.size() == N) 
    {
        cout << "YES\n";

        // 문제 요구: "가능한 답이 여러 개면 아무거나"
        // 굳이 오름차순 정렬할 필요는 없으나, 예쁘게 출력해도 무방
        // 예: 그냥 현재 순서대로 출력
        for (int i = 0; i < N; i++) 
        {
            cout << A[i] << (i + 1 < N ? ' ' : '\n');
        }
    }
    else 
    {
        cout << "NO\n";
    }

    return 0;
}
