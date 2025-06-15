#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() 
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int N, K;
    cin >> N >> K;

    string s;
    cin >> s;

    int freq[26] = { 0 };

    for (char c : s) 
    {
        freq[c - 'a']++;
    }

    int uniqueCount = 0;

    for (int i = 0; i < 26; i++) 
    {
        if (freq[i] > 0) 
        {
            uniqueCount++;
        }
    }

    if (uniqueCount < 26)
    {
        cout << 1 << "\n";
    }
    else 
    {
        int minFreq = freq[0];

        for (int i = 1; i < 26; i++) 
        {
            minFreq = min(minFreq, freq[i]);
        }

        cout << (K >= minFreq ? 1 : 0) << "\n";
    }

    return 0;
}