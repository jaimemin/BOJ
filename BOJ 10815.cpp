#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    cin >> N;

    unordered_set<int> cardSet; // 상근이가 가지고 있는 숫자 카드를 저장

    for (int i = 0; i < N; i++) 
    {
        int num;
        cin >> num;

        cardSet.insert(num); // 숫자 카드를 집합에 추가
    }

    cin >> M;

    vector<int> queries(M);

    for (int i = 0; i < M; i++) 
    {
        cin >> queries[i];
    }

    for (int i = 0; i < M; i++) 
    {
        if (cardSet.find(queries[i]) != cardSet.end())
        {
            cout << "1 "; // 숫자 카드가 존재하면 1 출력
        }
        else 
        {
            cout << "0 "; // 존재하지 않으면 0 출력
        }
    }

    return 0;
}
