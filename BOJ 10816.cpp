#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    cin >> N;

    unordered_map<int, int> card2cnt;

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;

        card2cnt[num]++;
    }

    cin >> M;

    vector<int> query(M);

    for (int i = 0; i < M; i++) 
    {
        cin >> query[i];
    }

    for (int i = 0; i < M; i++) 
    {
        cout << card2cnt[query[i]] << " ";
    }

    return 0;
}