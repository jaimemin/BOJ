#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<int> mushrooms(10);

    for (int i = 0; i < 10; i++)
    {
        cin >> mushrooms[i];
    }

    int sum = 0, closest = 0;

    for (int i = 0; i < 10; i++)
    {
        sum += mushrooms[i];

        if (abs(100 - sum) <= abs(100 - closest))
        {
            closest = sum;
        }
        else 
        {

            break;
        }
    }

    cout << closest << '\n';

    return 0;
}