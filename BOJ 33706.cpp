#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;

    vector<bool> hasSmall(N + 1, false);

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;

        hasSmall[b] = true;
    }

    for (int i = 2; i <= N; i++)
    {
        if (!hasSmall[i]) 
        {
            cout << "NO\n";

            return 0;
        }
    }

    cout << "YES\n";

    return 0;
}