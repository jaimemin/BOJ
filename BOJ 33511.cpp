#include <iostream>
#include <vector>
using namespace std;

const int MAX = 2e3 + 2;

int N, M;

int friendsArr[MAX][MAX];

bool validateCandidate(const vector<int>& A)
{
    for (int i = 0; i < N; i++) 
    {
        int diffCount = 0;

        for (int j = 0; j < M; j++) 
        {
            if (A[j] != friendsArr[i][j])
            {
                diffCount++;
            }

            if (diffCount > 1)
            {
                break;
            }
        }

        if (diffCount != 1)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;

    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < M; j++) 
        {
            cin >> friendsArr[i][j];
        }
    }

    vector<int> candidate;

    for (int i = 0; i < M; i++) 
    {
        candidate.push_back(friendsArr[0][i]);
    }

    int refFriendIndex = -1;
    vector<int> diffIndices;

    for (int i = 1; i < N; i++) 
    {
        vector<int> currDiff;

        for (int j = 0; j < M; j++)
        {
            if (candidate[j] != friendsArr[i][j])
            {
                currDiff.push_back(j);
            }
        }

        if (currDiff.size() == 2)
        {
            refFriendIndex = i;
            diffIndices = currDiff;

            break;
        }
    }

    if (refFriendIndex != -1)
    {
        for (int idx : diffIndices) 
        {
            vector<int> A = candidate;
            A[idx] = friendsArr[refFriendIndex][idx];

            if (validateCandidate(A)) 
            {
                for (int j = 0; j < M; j++)
                {
                    cout << A[j] << (j + 1 == M ? "\n" : " ");
                }

                return 0;
            }
        }
    }
    else 
    {
        int pos = -1;

        for (int i = 1; i < N; i++) 
        {
            for (int j = 0; j < M; j++)
            {
                if (candidate[j] != friendsArr[i][j])
                {
                    pos = j;

                    break;
                }
            }

            if (pos != -1)
            {
                break;
            }
        }

        if (pos == -1)
        {
            pos = 0;
        }

        int newVal = 0;

        if (newVal == candidate[pos])
        {
            newVal = 2000;
        }

        vector<int> A = candidate;
        A[pos] = newVal;

        if (validateCandidate(A)) 
        {
            for (int j = 0; j < M; j++)
            {
                cout << A[j] << (j + 1 == M ? "\n" : " ");
            }

            return 0;
        }
    }

    return 0;
}
