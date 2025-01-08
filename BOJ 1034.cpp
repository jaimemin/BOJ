#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

bool canActivateRow(const string& rowState, int M, int K)
{
    int offCnt = 0;

    for (char lamp : rowState) 
    {
        if (lamp == '0')
        {
            offCnt++;
        }
    }

    // 스위치를 눌러서 모든 0을 1로 바꿀 수 있는지 확인
    return (offCnt <= K) 
        && ((K - offCnt) % 2 == 0);
}

int getMaxActivatedRows(int N, int M, const vector<string>& v, int K) 
{
    unordered_map<string, int> rowFrequency;

    for (const string& rowState : v) 
    {
        rowFrequency[rowState]++;
    }

    int maxActivatedRows = 0;

    for (const auto& entry : rowFrequency)
    {
        const string& rowState = entry.first;
        int cnt = entry.second;

        if (canActivateRow(rowState, M, K)) 
        {
            maxActivatedRows = max(maxActivatedRows, cnt);
        }
    }

    return maxActivatedRows;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, M, K;
    cin >> N >> M;

    vector<string> v(N);

    for (int i = 0; i < N; i++) 
    {
        cin >> v[i];
    }

    cin >> K;

    cout << getMaxActivatedRows(N, M, v, K) << "\n";
    
    return 0;
}
