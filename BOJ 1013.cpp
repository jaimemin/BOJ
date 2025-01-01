#include <iostream>
#include <regex>
#include <string>
using namespace std;

int main() 
{
    int T;
    cin >> T;
    cin.ignore();

    regex pattern("(100+1+|01)+");

    while (T--) {
        string signal;
        cin >> signal;

        if (regex_match(signal, pattern)) 
        {
            cout << "YES" << "\n";
        }
        else 
        {
            cout << "NO" << "\n";
        }
    }

    return 0;
}
