#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    int sum = 0;
    
    while (cin >> s)
    {
        if (s == "<br>")
        {
            cout << "\n";
            
            sum = 0;
        }
        else if (s == "<hr>")
        {
            if (sum)
            {
                cout << "\n";
                
                sum = 0;
            }
            
            for (int i = 0; i < 80; i++)
            {
                cout << "-";
            }
            
            cout << "\n";
        }
        else
        {
            int len = s.length();
            
            if (sum + len + 1 > 80)
            {
                cout << "\n";
                
                sum = 0;
            }
            
            if (sum)
            {
                cout << " ";
                
                sum++;
            }
            
            cout << s;
            sum += len;
        }
    }
    
    return 0;
}
