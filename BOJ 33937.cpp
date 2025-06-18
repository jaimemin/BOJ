#include <iostream>
#include <string>
using namespace std;

bool isVowel(char c) 
{
    return c == 'a' 
        || c == 'e'
        || c == 'i'
        || c == 'o' 
        || c == 'u';
}

string getFirstSyllable(const string& s)
{
    int n = s.size();
    int vowelIdx = -1;

    for (int i = 0; i < n; i++)
    {
        if (isVowel(s[i])) 
        {
            vowelIdx = i;

            break;
        }
    }

    if (vowelIdx == -1)
    {
        return "";
    }

    int consonantIdx = -1;

    for (int i = vowelIdx + 1; i < n; i++)
    {
        if (!isVowel(s[i])) 
        {
            consonantIdx = i;

            break;
        }
    }

    if (consonantIdx == -1)
    {
        return "";
    }

    return s.substr(0, consonantIdx);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string SA, SB;
    cin >> SA >> SB;

    string firstSyllableA = getFirstSyllable(SA);
    string firstSyllableB = getFirstSyllable(SB);

    if (firstSyllableA.empty() || firstSyllableB.empty()) 
    {
        cout << "no such exercise\n";
    }
    else 
    {
        cout << firstSyllableA << firstSyllableB << "\n";
    }

    return 0;
}