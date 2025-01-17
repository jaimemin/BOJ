#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// freq[x] == 0 이 아닌 'x'의 개수를 추적하기 위한 전역 개념 설명용
// 코드에서는 static 변수/함수 안 쓰고 지역적으로 관리합니다.

// freq[x] 값을 갱신하면서 mismatchCount를 조정해주는 함수
//  - d > 0 이면 "왼쪽 구간에 원소 x를 d번 추가" (freq[x] += d)
//  - d < 0 이면 "오른쪽 구간에 원소 x를 -d번 추가"와 같은 효과 (freq[x] -= |d|)
//
// freq[x]가 0에서 d로 바뀌면 mismatchCount가 1 증가
// freq[x]가 d에서 0으로 바뀌면 mismatchCount가 1 감소
void updateFreq(vector<int>& freq, int& mismatchCount, int x, int d) 
{
    int oldVal = freq[x];
    int newVal = oldVal + d;
    freq[x] = newVal;

    // oldVal == 0 이었는데 newVal != 0 이 된 경우 => mismatchCount++
    if (oldVal == 0 && newVal != 0)
    {
        mismatchCount++;
    }
    // oldVal != 0 이었는데 newVal == 0 이 된 경우 => mismatchCount--
    else if (oldVal != 0 && newVal == 0)
    {
        mismatchCount--;
    }
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;

    vector<long long> A(N);

    for (int i = 0; i < N; i++) 
    {
        cin >> A[i];
    }

    // == 좌표 압축 ==
    // 1) copy & sort & unique
    vector<long long> comp = A;
    sort(comp.begin(), comp.end());
    comp.erase(unique(comp.begin(), comp.end()), comp.end());
    // 2) 함수 getID
    auto getID = [&](long long x)
    {
        // lower_bound 로 위치 찾기
        return int(std::lower_bound(comp.begin(), comp.end(), x) - comp.begin());
    };
    // 실제 A를 압축 값으로 대체
    for (int i = 0; i < N; i++)
    {
        A[i] = getID(A[i]);
    }

    // 압축된 값의 최댓값 + 1 = comp.size()
    int distinctCount = (int)comp.size();

    int ans = 0;  // 조건 만족하는 최대 짝수 길이

    // i 와 i+1 사이를 "가운데 경계"로 잡는다 (0-based 기준)
    // => 초기 구간은 [i, i+1]
    // => 길이 2부터 시작해서 좌우로 확장할 때마다 2씩 증가
    for (int i = 0; i < N - 1; i++)
    {
        // freq[x] = 왼쪽 구간 개수 - 오른쪽 구간 개수
        // 전부 0이면 왼=오른쪽 멀티셋 동일
        vector<int> freq(distinctCount, 0);
        int mismatchCount = 0;

        // 초기 구간: [i, i+1] (길이 2)
        // 왼쪽 구간에 A[i], 오른쪽 구간에 A[i+1]이 있다고 생각:
        updateFreq(freq, mismatchCount, A[i], +1);
        updateFreq(freq, mismatchCount, A[i + 1], -1);

        // 만약 mismatchCount == 0이면 길이=2 구간부터 이미 가능
        if (mismatchCount == 0)
        {
            ans = max(ans, 2);
        }

        // 좌우로 확장
        int left = i, right = i + 1;

        while (left > 0 && right < N - 1)
        {
            left--;   // 한 칸 왼쪽 확장
            right++;  // 한 칸 오른쪽 확장
            // 새롭게 포함된 왼쪽 원소
            updateFreq(freq, mismatchCount, A[left], +1);
            // 새롭게 포함된 오른쪽 원소
            updateFreq(freq, mismatchCount, A[right], -1);

            if (mismatchCount == 0)
            {
                int length = (right - left + 1); // 현재 구간 길이

                ans = max(ans, length);
            }
        }
    }

    cout << ans << "\n";

    return 0;
}