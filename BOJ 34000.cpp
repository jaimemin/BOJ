#include <iostream>
#include <vector>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, Q;
    cin >> N >> Q;

    vector<int> a(N + 1);

    for (int i = 1; i <= N; i++)
    {
        cin >> a[i];
    }

    vector<int> typeSign(N + 1);

    for (int t = 1; t <= N; t++)
    {
        int b;
        cin >> b;

        typeSign[t] = (b == 1 ? 1 : -1);
    }

    vector<int> count(N + 1, 0);

    for (int i = 1; i <= N; i++) 
    {
        count[a[i]]++;
    }

    long long totalHappiness = 0;

    for (int t = 1; t <= N; t++) 
    {
        totalHappiness += 1LL * count[t] * typeSign[t];
    }

    while (Q--)
    {
        int type;
        cin >> type;

        if (type == 1)
        {
            int i, j;
            cin >> i >> j;

            int oldType = a[i];
            int newType = j;

            if (oldType != newType) 
            {
                int oldSign = typeSign[oldType];
                int newSign = typeSign[newType];

                totalHappiness += (newSign - oldSign);
                count[oldType]--;
                count[newType]++;
                a[i] = newType;
            }
        }
        else 
        {
            int t;
            cin >> t;

            int oldSign = typeSign[t];
            int cnt = count[t];

            totalHappiness -= 2LL * oldSign * cnt;
            typeSign[t] = -oldSign;
        }

        long long T = totalHappiness;
        long long answer = (T * T) / 4;

        cout << answer << '\n';
    }

    return 0;
}