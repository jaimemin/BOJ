#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 3e5 + 3e2;

int N;

long long A[MAX];

long long cache[MAX];

long long tree[MAX];

void update(int idx, long long value)
{
	while (idx <= N)
	{
		tree[idx] = max(tree[idx], value);
		
		idx += idx & -idx;
	}
}

long long query(int idx)
{
	long long result = 0;
	
	while (idx)
	{
		result = max(result, tree[idx]);
		
		idx -= idx & -idx;
	}
	
	return result;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
		
		cache[i] = A[i];
	}
	
	sort(cache, cache + N);
	
	for (int i = 0; i < N; i++)
	{
		int idx = lower_bound(cache, cache + N, A[i]) - cache + 1;
		long long pSum = query(idx - 1);
		
		update(idx, pSum + A[i]);
	}
	
	cout << query(N) << "\n";
	
	return 0;
}
