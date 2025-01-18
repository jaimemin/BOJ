#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 최대 N (배열 크기)
static const int MAXN = 100000;
// 쿼리 최대 개수
static const int MAXM = 5000;

// 입력 배열 (1-based)
int a[MAXN + 1];

// 좌표 압축 관련
int compArr[MAXN + 1];         // a[i] 값을 압축한 결과를 저장

vector<long long> uniqVal;   // 중복 제거된(정렬된) 원본 값들을 저장

// 세그먼트 트리 배열 (퍼시스턴트)
int leftChild[40'000'00];   // 왼쪽 자식 인덱스

int rightChild[40'000'00];  // 오른쪽 자식 인덱스

int segSum[40'000'00];      // 이 노드가 관리하는 구간의 합(개수)

int root[MAXN + 1];           // 각 버전(0~n)의 루트 노드 번호

int nodeCount = 0;          // 세그먼트 트리 노드가 몇 개 만들어졌는지

// 세그먼트 트리 build (빈 트리 생성) - 사실상 필요 없다면 생략 가능
// 여기서는 특별히 초기 빈 노드를 리턴할 필요가 없어서 사용 X

// update(prev, start, end, pos, val):
//  이전 버전 prev 트리를 복사하여 [pos] 위치에 val 더한 새로운 노드 반환
int update(int prevNode, int start, int end, int pos, int val)
{
    // 새 노드 하나 생성
    int curr = ++nodeCount;

    // 이전 노드의 정보 복사
    leftChild[curr] = leftChild[prevNode];
    rightChild[curr] = rightChild[prevNode];
    segSum[curr] = segSum[prevNode] + val;

    // 리프가 아니면 자식들 재귀 업데이트
    if (start < end)
    {
        int mid = (start + end) / 2;

        if (pos <= mid)
        {
            int newLeft = update(leftChild[prevNode], start, mid, pos, val);
            leftChild[curr] = newLeft;
        }
        else 
        {
            int newRight = update(rightChild[prevNode], mid + 1, end, pos, val);
            rightChild[curr] = newRight;
        }
    }

    return curr;
}

// query(u, v, start, end, k):
//  버전 u, v (세그먼트)의 차이를 이용하여
//  구간 [start, end] 내에서 "k번째 수"의 압축값을 찾는다.
int query(int u, int v, int start, int end, int k) 
{
    // 리프에 도달하면, start == end == "k번째로 작은 값"의 압축 인덱스
    if (start == end) 
    {
        return start;
    }

    int mid = (start + end) >> 1;
    // 왼쪽 자식에 들어있는 원소 개수 (버전 v - 버전 u)
    int leftCount = segSum[leftChild[v]] - segSum[leftChild[u]];

    if (leftCount >= k)
    {
        // 왼쪽 자식으로 이동
        return query(leftChild[u], leftChild[v], start, mid, k);
    }

    // 오른쪽 자식으로 이동, k를 조정
    return query(rightChild[u], rightChild[v], mid + 1, end, k - leftCount);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;

    // 1. 배열 입력
    for (int i = 1; i <= n; i++) 
    {
        cin >> a[i];

        uniqVal.push_back(a[i]);
    }

    // 2. 좌표 압축
    sort(uniqVal.begin(), uniqVal.end());
    uniqVal.erase(unique(uniqVal.begin(), uniqVal.end()), uniqVal.end());
    // 압축 값 범위: [1 .. uniqVal.size()]

    // compArr[i] = a[i]의 압축값
    for (int i = 1; i <= n; i++) 
    {
        // lower_bound로 찾아 인덱스를 +1
        int idx = int(lower_bound(uniqVal.begin(), uniqVal.end(), a[i]) - uniqVal.begin()) + 1;

        compArr[i] = idx;
    }

    // 3. 퍼시스턴트 세그먼트 트리 구성
    //    root[0] = 0 (빈 트리)로 놓고, i=1..n에 대해 업데이트
    for (int i = 1; i <= n; i++)
    {
        root[i] = update(root[i - 1], 1, (int)uniqVal.size(), compArr[i], 1);
    }

    // 4. 쿼리 처리
    while (m--)
    {
        int i, j, k;
        cin >> i >> j >> k;
        // i..j 구간에서 k번째 작은 수
        // => query(root[i-1], root[j], 1, size, k)
        // (주의) i=1일 때, root[0]은 빈 트리

        int compIndex = query(root[i - 1], root[j], 1, (int)uniqVal.size(), k);
        // compIndex를 원래 값으로 역변환
        long long answer = uniqVal[compIndex - 1]; // 벡터는 0-based

        cout << answer << "\n";
    }

    return 0;
}