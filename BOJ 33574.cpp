#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;

    vector<int> S;

    while (T--) 
    {
        int type;
        cin >> type;

        if (type == 1)
        {
            int x;
            cin >> x;

            if (x == 1) 
            {
                sort(S.begin(), S.end());
            }
            else 
            {
                sort(S.begin(), S.end(), greater<int>());
            }
        }
        else
        {
            int x, t;
            cin >> x >> t;

            S.insert(S.begin() + x, t);
        }
    }

    cout << S.size() << "\n";

    for (int i = 0; i < (int)S.size(); i++) 
    {
        if (i)
        {
            cout << ' ';
        }

        cout << S[i];
    }

    cout << "\n";

    return 0;
}