#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string S;
    cin >> S;

    int q;
    cin >> q;

    int n = S.size();
    vector<vector<int>> prefixCnt(26, vector<int>(n + 1, 0));

    // Build prefix cnt array for each character
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            prefixCnt[j][i + 1] = prefixCnt[j][i];
        }

        prefixCnt[S[i] - 'a'][i + 1]++;
    }

    while (q--) 
    {
        char alpha;
        int l, r;
        cin >> alpha >> l >> r;

        int charIndex = alpha - 'a';
        int cnt = prefixCnt[charIndex][r + 1] - prefixCnt[charIndex][l];

        cout << cnt << '\n';
    }

    return 0;
}