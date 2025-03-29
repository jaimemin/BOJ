#include <iostream>
#include <string>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;

    string binary;
    cin >> binary;

    long long oddOperations = 0;
    int carry = 0;

    for (int i = binary.size() - 1; i > 0; i--)
    {
        int digit = binary[i] - '0';
        int effective = digit + carry;

        if (effective % 2 == 1) 
        {
            oddOperations++;

            carry = 1;
        }
    }

    cout << oddOperations << "\n";

    return 0;
}