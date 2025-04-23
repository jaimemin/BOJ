#include <iostream>
#include <string>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    getline(cin, s);

    int countHoles = 0;

    for (char ch : s) 
    {
        if (ch == '@')
        {
            countHoles++;
        }
        else if (ch >= 'A' && ch <= 'Z') 
        {
            if (ch == 'B') 
            {
                countHoles += 2;
            }
            else if (ch == 'A' || ch == 'D' || ch == 'O' 
                || ch == 'P' || ch == 'Q' || ch == 'R') 
            {
                countHoles++;
            }
        }
        else if (ch >= 'a' && ch <= 'z') 
        {
            if (ch == 'a' || ch == 'b' || ch == 'd' || ch == 'e' ||
                ch == 'g' || ch == 'o' || ch == 'p' || ch == 'q') {
                countHoles++;
            }
        }
    }

    cout << countHoles << "\n";

    return 0;
}