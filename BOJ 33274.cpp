include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> buildMatrix(vector<long long> rowSum, vector<long long> colSum)
{
    int N = rowSum.size();
    vector<vector<int>> A(N, vector<int>(N, 0));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            long long x = min(rowSum[i], colSum[j]);

            if (x > 10000)
            {
                x = 10000;
            }

            A[i][j] = (int)x;
            rowSum[i] -= x;
            colSum[j] -= x;
        }
    }

    return A;
}

void buildSetsEven(int N, vector<long long>& R, vector<long long>& C)
{
    R.clear();
    C.clear();
    R.reserve(N);
    C.reserve(N);

    for (int i = 0; i < N; i++) 
    {
        if (i % 2 == 0) 
        {
            R.push_back(i);
            R.push_back((2LL * N - 1) - i);
        }
        else 
        {
            C.push_back(i);
            C.push_back((2LL * N - 1) - i);
        }
    }
}

void buildSetsOdd(int N, vector<long long>& R, vector<long long>& C)
{
    R.clear();
    C.clear();
    R.reserve(N);
    C.reserve(N);

    long long M = 2LL * N - 2;
    long long half = M / 2;
    
    for (long long i = 1; i <= half; i++) 
    {
        if (i % 2 == 1) 
        {
            R.push_back(i);
            R.push_back((M + 1) - i);
        }
        else 
        {
            C.push_back(i);
            C.push_back((M + 1) - i);
        }
    }

    R.push_back(0);
    C.push_back(0);
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;

    if (N == 1) 
    {
        cout << 0 << "\n";

        return 0;
    }

    vector<long long> rowSum, colSum;

    if (N % 2 == 0) 
    {
        buildSetsEven(N, rowSum, colSum);
    }
    else
    {
        buildSetsOdd(N, rowSum, colSum);
    }

    auto A = buildMatrix(rowSum, colSum);

    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < N; j++)
        {
            cout << A[i][j] << (j + 1 < N ? ' ' : '\n');
        }
    }

    return 0;
}
