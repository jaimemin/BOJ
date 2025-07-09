#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int r, c;
    cin >> r >> c;

    int K;
    cin >> K;

    string S;
    cin >> S;

    vector<pair<int, int>> cycle = {
        {1,1}, {1,2}, {2,2}, {3,2},
        {4,2}, {4,1}, {3,1}, {2,1}
    };

    int pos2idx[5][3];
    memset(pos2idx, -1, sizeof(pos2idx));

    for (int i = 0; i < 8; i++) 
    {
        pos2idx[cycle[i].first][cycle[i].second] = i;
    }

    for (char cmd : S) 
    {
        if (cmd == 'A') 
        {
            if (r <= 2)
            {
                r += 2;
            }
            else
            {
                r -= 2;
            }
        }
        else if (cmd == 'B')
        {
            if (r <= 2) 
            {
                if (r == 1 && c == 1) 
                {
                    r = 2; 
                    c = 2;
                }
                else if (r == 1 && c == 2) 
                {
                    r = 2; 
                    c = 1;
                }
                else if (r == 2 && c == 1) 
                {
                    r = 1;
                    c = 2;
                }
                else
                { 
                    r = 1;
                    c = 1; 
                }
            }
            else 
            {
                if (r == 3 && c == 1) 
                { 
                    r = 4; 
                    c = 2; 
                }
                else if (r == 3 && c == 2)
                { 
                    r = 4;
                    c = 1;
                }
                else if (r == 4 && c == 1)
                { 
                    r = 3; 
                    c = 2; 
                }
                else 
                { 
                    r = 3;
                    c = 1; 
                }
            }
        }
        else if (cmd == 'C') 
        {
            if (r == 1 || r == 4)
            {
                if (r == 1 && c == 1)
                {
                    r = 4;
                    c = 2;
                }
                else if (r == 1 && c == 2) 
                { 
                    r = 4; 
                    c = 1; 
                }
                else if (r == 4 && c == 1)
                {
                    r = 1;
                    c = 2; 
                }
                else 
                {
                    r = 1;
                    c = 1; 
                }
            }
            else 
            {
                if (r == 2 && c == 1) 
                { 
                    r = 3;
                    c = 2; 
                }
                else if (r == 2 && c == 2)
                { 
                    r = 3; 
                    c = 1; 
                }
                else if (r == 3 && c == 1) 
                { 
                    r = 2;
                    c = 2; 
                }
                else 
                { 
                    r = 2; 
                    c = 1;
                }
            }
        }
        else 
        {
            int idx = pos2idx[r][c];
            int ni = (idx + 1) % 8;

            r = cycle[ni].first;
            c = cycle[ni].second;
        }
    }

    cout << r << ' ' << c << "\n";

    return 0;
}