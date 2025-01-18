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

    unordered_set<int> cardSet; // ����̰� ������ �ִ� ���� ī�带 ����

    for (int i = 0; i < N; i++) 
    {
        int num;
        cin >> num;

        cardSet.insert(num); // ���� ī�带 ���տ� �߰�
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
            cout << "1 "; // ���� ī�尡 �����ϸ� 1 ���
        }
        else 
        {
            cout << "0 "; // �������� ������ 0 ���
        }
    }

    return 0;
}
