#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;

    while (T--) 
    {
        string S;
        cin >> S;

        int n = S.size();
        int needLeft = n / 2, needRight = n / 2;
        int balance = 0;
        long long totalCost = 0;
        string answer;

        for (int i = 0; i < n; i++) 
        {
            int rem = n - i;
            char ch = S[i];
            bool chooseLeft;

            if (rem == needLeft) 
            {
                chooseLeft = true;
            }
            else if (balance == 0) {

                chooseLeft = true;
            }
            else
            {
                if (ch == 'C') 
                {
                    chooseLeft = (needLeft > 0);
                }
                else
                {
                    chooseLeft = false;
                }
            }

            if (chooseLeft) 
            {
                if (ch == 'U')
                {
                    totalCost += 1;
                }

                answer += "(";
                balance++;
                needLeft--;
            }
            else 
            {
                if (ch == 'C')
                {
                    totalCost += 2;
                }
                else
                {
                    totalCost += 1;
                }

                answer += ")";
                balance--;
                needRight--;
            }
        }

        cout << totalCost << "\n" << answer << "\n";
    }

    return 0;
}