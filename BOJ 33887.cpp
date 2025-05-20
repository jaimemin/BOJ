#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

vector<int> generateBinaryPalindromes(int maxLen = 31) 
{
    vector<int> pals;

    for (int len = 1; len <= maxLen; ++len) 
    {
        int halfLen = (len + 1) / 2;
        int start = 1 << (halfLen - 1);
        int end = 1 << halfLen;

        for (int half = start; half < end; half++) 
        {
            long long pal = half;
            long long tmp = half;

            if (len & 1) 
            {
                tmp >>= 1;
            }

            while (tmp) 
            {
                pal = (pal << 1) | (tmp & 1LL);
                
                tmp >>= 1;
            }
            
            pals.push_back((int)pal);
        }
    }

    sort(pals.begin(), pals.end());
    pals.erase(unique(pals.begin(), pals.end()), pals.end());
    
    return pals;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> pals = generateBinaryPalindromes();

    int T;
    cin >> T;
    
    while (T--) 
    {
        long long X;
        cin >> X;

        auto it = lower_bound(pals.begin(), pals.end(), (int)X);
        long long answer = LLONG_MAX;

        if (it != pals.end()) 
        {
            answer = min(answer, llabs((long long) * it - X));
        }
        
        if (it != pals.begin())
        {
            answer = min(answer, llabs((long long) * prev(it) - X));
        }

        cout << answer << "\n";
    }

    return 0;
}
