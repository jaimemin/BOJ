#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long N, M, K;
    cin >> N >> M >> K;

    // 1) 만약 N이 M보다 크면 불가능
    if (N > M)
    {
        cout << -1 << "\n";

        return 0;
    }

    // 제외된 수들을 보관할 자료구조 (최대 2N개까지 저장 가능)
    unordered_set<long long> excluded;
    vector<long long> result;

    long long candidate = 1; // 1부터 M까지 차례로 후보를 탐색

    while (result.size() < N) 
    {
        // 이미 제외된 수 또는 범위를 벗어나는 후보는 건너뛰기
        while (candidate <= M && excluded.find(candidate) != excluded.end()) 
        {
            candidate++;
        }

        // 후보가 M보다 커졌다면 더 이상 뽑을 수 없음
        if (candidate > M)
        {
            break;
        }

        // candidate를 결과에 추가
        result.push_back(candidate);

        // 이제 candidate 및 candidate ⊕ K를 제외 처리
        excluded.insert(candidate);

        long long xork = candidate ^ K;

        if (xork >= 1 && xork <= M)
        {
            excluded.insert(xork);
        }

        candidate++;
    }

    // N개의 수를 모두 뽑지 못했다면 불가능
    if (result.size() < N)
    {
        cout << -1 << "\n";

        return 0;
    }
    
    // 결과 출력
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << (i + 1 < result.size() ? ' ' : '\n');
    }

    return 0;
}