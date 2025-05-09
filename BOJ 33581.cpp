#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, K;
    cin >> N >> K;

    if (K == N)
    {
        cout << N;

        for (int i = 1; i < N; i++)
        {
            cout << " " << i;
        }

        cout << "\n";

        return 0;
    }

    if (K == N - 1) 
    {
        if (N <= 4) 
        {
            cout << -1 << '\n';

            return 0;
        }

        cout << 1;

        for (int x = N - 1; x >= 2; x--)
        {
            cout << " " << x;
        }

        cout << " " << N << "\n";

        return 0;
    }

    vector<int> answer;
    answer.push_back(K);
    answer.push_back(K + 1);

    for (int x = 1; x < K; x++)
    {
        answer.push_back(x);
    }

    for (int x = K + 3; x <= N; x++)
    {
        answer.push_back(x);
    }

    answer.push_back(K + 2);

    for (int i = 0; i < N; i++) 
    {
        if (i)
        {
            cout << " ";
        }

        cout << answer[i];
    }

    cout << "\n";

    return 0;
}
