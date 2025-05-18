#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isVowel(char c) 
{
    return c == 'a' 
        || c == 'e' 
        || c == 'i' 
        || c == 'o' 
        || c == 'u';
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string S;
    cin >> S;

    vector<int> vowelPos;

    for (int i = 0; i < (int)S.size(); i++) 
    {
        if (isVowel(S[i])) 
        {
            vowelPos.push_back(i + 1);
        }
    }

    if (vowelPos.empty()) 
    {
        cout << -1 << "\n";

        return 0;
    }

    char last = S.back();
    int answer = -1;

    if (isVowel(last) || last == 'n' || last == 's') 
    {
        if (vowelPos.size() >= 2) 
        {
            answer = vowelPos[vowelPos.size() - 2];
        }
    }
    else 
    {
        answer = vowelPos.back();
    }

    cout << answer << "\n";

    return 0;
}