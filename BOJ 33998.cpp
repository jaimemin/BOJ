#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <array>
using namespace std;

struct signature 
{
    array<int, 26> a;

    bool operator==(signature const& other) const 
    {
        return a == other.a;
    }
};

struct signatureHash 
{
    size_t operator()(signature const& sig) const noexcept 
    {
        size_t h = 0;

        for (int c = 0; c < 26; c++) 
        {
            h = h * 1000003 + sig.a[c];
        }

        return h;
    }
};

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;

    string s;
    cin >> s;
    
    vector<string> queries(M);

    for (int i = 0; i < M; i++)
    {
        cin >> queries[i];
    }

    unordered_map<int, vector<int>> queriesByLength;

    for (int i = 0; i < M; i++) 
    {
        queriesByLength[queries[i].size()].push_back(i);
    }

    vector<array<int, 26>> prefixCounts(N + 1);

    for (int c = 0; c < 26; c++)
    {
        prefixCounts[0][c] = 0;
    }

    for (int i = 0; i < N; i++) 
    {
        prefixCounts[i + 1] = prefixCounts[i];
        prefixCounts[i + 1][s[i] - 'a']++;
    }

    vector<long long> answer(M, 0);

    for (auto& entry : queriesByLength) 
    {
        int len = entry.first;
        auto& indices = entry.second;

        if (len > N)
        {
            continue;
        }

        unordered_map<signature, int, signatureHash> signatureToId;
        signatureToId.reserve(indices.size() * 2);

        vector<int> signatureIdForQuery(indices.size());
        int idCount = 0;

        for (int j = 0; j < (int)indices.size(); j++) 
        {
            signature querySignature;
            querySignature.a.fill(0);

            for (char ch : queries[indices[j]])
            {
                querySignature.a[ch - 'a']++;
            }

            auto it = signatureToId.find(querySignature);

            if (it == signatureToId.end()) 
            {
                signatureToId[querySignature] = idCount;
                signatureIdForQuery[j] = idCount;

                ++idCount;
            }
            else
            {
                signatureIdForQuery[j] = it->second;
            }
        }

        vector<long long> countForSignature(idCount, 0);
        signature windowSignature;

        for (int pos = 0; pos + len <= N; pos++)
        {
            for (int c = 0; c < 26; c++)
            {
                windowSignature.a[c] = prefixCounts[pos + len][c] - prefixCounts[pos][c];
            }

            auto it = signatureToId.find(windowSignature);

            if (it != signatureToId.end())
            {
                ++countForSignature[it->second];
            }
        }

        for (int j = 0; j < (int)indices.size(); j++) 
        {
            answer[indices[j]] = countForSignature[signatureIdForQuery[j]];
        }
    }

    for (auto val : answer) 
    {
        cout << val << '\n';
    }

    return 0;
}