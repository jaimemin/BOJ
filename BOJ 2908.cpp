#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int reverseNumber(int number) 
{
    string strNum = std::to_string(number);
    reverse(strNum.begin(), strNum.end());

    return stoi(strNum);
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a, b;
    cin >> a >> b;

    int reversedA = reverseNumber(a);
    int reversedB = reverseNumber(b);

    if (reversedA > reversedB) 
    {
        std::cout << reversedA << "\n";
    }
    else 
    {
        std::cout << reversedB << "\n";
    }

    return 0;
}
