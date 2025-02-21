#include <iostream>
#include <vector>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;

    int winner = -1;
    int highestMod = -1;

    for (int i = 1; i <= N; i++)
    {
        vector<int> cards(5, 0);

        for (int j = 0; j < 5; j++) 
        {
            cin >> cards[j];
        }

        int tempMax = -1;

        for (int a = 0; a < 3; a++)
        {
            for (int b = a + 1; b < 4; b++) 
            {
                for (int c = b + 1; c < 5; c++)
                {
                    int sum = cards[a] + cards[b] + cards[c];
                    int mod = sum % 10;

                    if (mod > tempMax) 
                    {
                        tempMax = mod;
                    }
                }
            }
        }

        if (tempMax > highestMod)
        {
            highestMod = tempMax;

            winner = i;
        }
        else if (tempMax == highestMod) 
        {
            if (i > winner)
            {
                winner = i;
            }
        }
    }

    cout << winner << "\n";

    return 0;
}
