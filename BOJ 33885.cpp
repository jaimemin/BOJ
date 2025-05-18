#include <iostream>
#include <string>
#include <vector>
using namespace std;

int dayIndex(string s)
{
    if (s == "MON")
    {
        return 0;
    }

    if (s == "TUE")
    {
        return 1;
    }

    if (s == "WED")
    {
        return 2;
    }

    if (s == "THU")
    {
        return 3;
    }

    return 4;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;

    vector<int> credit(N);
    vector<vector<pair<int, int>>> lectures(N);

    for (int i = 0; i < N; i++) 
    {
        int c, s;
        cin >> c >> s;

        credit[i] = c;

        for (int j = 0; j < s; j++) 
        {
            string d;
            int h;
            cin >> d >> h;

            lectures[i].push_back({ dayIndex(d), h });
        }
    }

    int totalMasks = 1 << N;

    for (int mask = 1; mask < totalMasks; mask++) 
    {
        bool used[5][24] = { false };
        int sumCredit = 0;
        bool conflict = false;

        for (int i = 0; i < N; i++)
        {
            if (!(mask & (1 << i)))
            {
                continue;
            }

            sumCredit += credit[i];

            for (auto lec : lectures[i])
            {
                int d = lec.first;
                int h = lec.second;

                if (used[d][h]) 
                {
                    conflict = true;

                    break;
                }

                used[d][h] = true;
            }

            if (conflict)
            {
                break;
            }
        }

        if (!conflict && sumCredit >= M) 
        {
            cout << "YES\n";

            return 0;
        }
    }

    cout << "NO\n";

    return 0;
}