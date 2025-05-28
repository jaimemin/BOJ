#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    long long K;
    cin >> N >> M >> K;

    vector<long long> sheepSizes(N), wolfSizes(M);

    for (int i = 0; i < N; i++)
    {
        cin >> sheepSizes[i];
    }

    for (int i = 0; i < M; i++)
    {
        cin >> wolfSizes[i];
    }

    sort(sheepSizes.begin(), sheepSizes.end());
    sort(wolfSizes.begin(), wolfSizes.end());

    long long pensSheep = 0;
    bool hasSingleSheep = false;
    long long minSingleSheep = LLONG_MAX;
    int left = 0, right = N - 1;

    while (left <= right)
    {
        if (left == right)
        {
            pensSheep++;
            hasSingleSheep = true;
            minSingleSheep = min(minSingleSheep, sheepSizes[left]);

            break;
        }

        if (sheepSizes[left] + sheepSizes[right] <= K)
        {
            pensSheep++;
            left++;
            right--;
        }
        else
        {
            pensSheep++;
            hasSingleSheep = true;
            minSingleSheep = min(minSingleSheep, sheepSizes[right]);
            right--;
        }
    }

    long long pensWolf = 0;
    bool hasSingleWolf = false;
    long long minSingleWolf = LLONG_MAX;
    left = 0;
    right = M - 1;

    while (left <= right)
    {
        if (left == right)
        {
            pensWolf++;
            hasSingleWolf = true;
            minSingleWolf = min(minSingleWolf, wolfSizes[left]);

            break;
        }

        if (wolfSizes[left] + wolfSizes[right] <= K)
        {
            pensWolf++;
            left++;
            right--;
        }
        else
        {
            pensWolf++;
            hasSingleWolf = true;
            minSingleWolf = min(minSingleWolf, wolfSizes[right]);
            right--;
        }
    }

    long long result = pensSheep + pensWolf;

    if (hasSingleSheep && hasSingleWolf
        && minSingleSheep + minSingleWolf <= K) 
    {
        result--;
    }

    cout << result << "\n";

    return 0;
}
