#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;

    vector<long long> decreasingNumbers;

    for (int i = 0; i <= 9; i++) 
    {
        decreasingNumbers.push_back(i);
    }

    for (int i = 0; i < decreasingNumbers.size(); i++) 
    {
        long long currentNumber = decreasingNumbers[i];
        int lastDigit = currentNumber % 10;

        for (int nextDigit = 0; nextDigit < lastDigit; nextDigit++) 
        {
            decreasingNumbers.push_back(currentNumber * 10 + nextDigit);
        }

        if (decreasingNumbers.size() > N) 
        {
            break;
        }
    }

    cout << (N < decreasingNumbers.size() ? decreasingNumbers[N] : -1) << "\n";

    return 0;
}