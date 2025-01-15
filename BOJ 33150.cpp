#include <iostream>
#include <algorithm>
using namespace std;

static const int MAXN = 200000;        // 최대 Q

static const int LOGN = 20;           // log2(200000) ~= 18~19 정도

// LCA를 위한 자료구조
// lca[v][k] = v의 2^k번째 조상
int parentArr[MAXN + 2][LOGN];

long long depthArr[MAXN + 2];  // root(1번)으로부터의 거리

int Q;

// LCA(최소공통조상) 구하기
int getLCA(int a, int b) 
{
    if (a == b)
    {
        return a;
    }

    // 깊이가 다른 경우 depth 맞추기
    if (depthArr[a] < depthArr[b])
    {
        swap(a, b);
    }

    // 1) a의 depth를 b와 같게 올린다.
    long long diff = depthArr[a] - depthArr[b];
    // 깊이 차가 곧 간선수(가중치가 아니라 '트리 높이' 관점)인 것이 아니라,
    // 여기선 "깊이"를 '루트~노드까지의 거리'로 썼으므로 단순히 diff만큼 점프해선 안 됩니다.
    // ------
    // 하지만 "LCA 테이블"에서의 parentArr[..]는 '트리 레벨 관점(1단계 조상)'이 아니라
    // '논리적 2^k번째 조상'을 저장했다고 볼 때,
    // 깊이(트리 레벨) 자체가 아니라, "2^k번 위로"를 어떻게 점프할지가 다른 관점이 됩니다.
    // ------
    // 일반적으로는 "트리의 레벨" (루트와의 간선 개수)을 써서 처리하는 것이 정석입니다.
    // 여기서는 depthArr[a]를 "루트~a까지의 누적 가중치"로 썼습니다.
    // 즉, 가중치 합으로 정의된 depthArr에서는 '레벨'이 아니라 단순히 거리이므로
    // '2^k' 점프와 직접 연관 짓기 어렵습니다.
    //
    // => 따라서, 보통 가중치 트리에서 "LCA를 구할 때"는
    //    parentArr[a][k] = a의 2^k번째 '조상(부모의 부모...)' (트리 구조로서)
    //    레벨(간선 수) 관점으로는 a에서 위로 2^k번 올라간 노드.
    // => 그럼 "a와 b의 (트리상) 레벨"을 맞추는 과정을 먼저 해야 합니다.
    //    레벨[a] = 레벨[parent[a]] + 1 이런 식의 '간선 개수' 기반 레벨을 하나 더 두면 됩니다.
    // => 그리고 거리 계산은 depthArr[a] + depthArr[b] - 2*depthArr[LCA(a,b)] 로 하면 됩니다.
    //
    // -- 정리 --
    //   (1) LCA를 구하기 위해선 "트리 높이(간선 수 기준)"를 저장해야 함. (level[])
    //   (2) depthArr[] = "루트와의 거리(가중치 합)"는 따로 두고, 거리는 나중에 계산할 때만 사용.
    //   (3) parentArr[v][k] = v의 2^k번째 조상(간선 따라 k번 올라감).
    //
    // 아래에서는 level[]을 새로 두어 처리하겠습니다.

    // 우선 여기 코드를 간단히 수정해서 level[] 기반으로 LCA를 구하는 식으로 다시 짜겠습니다.
    // (depthArr는 거리 계산용으로만 사용)

    return -1; // 일단 함수 전체를 밑에서 다시 구현하므로 여기선 임시 리턴
}

// (수정) 레벨(간선 수 기준)과 가중치 기반 depth(거리) 둘 다 관리
int levelArr[MAXN + 2];

// level을 맞춰주는 함수
int LCA(int a, int b) {
    // 1) 레벨이 다르면 위로 끌어올려서 맞춤
    if (levelArr[a] < levelArr[b])
    {
        swap(a, b);
    }

    int diff = levelArr[a] - levelArr[b];

    for (int i = 0; i < LOGN; i++) 
    {
        if (diff & (1 << i)) 
        {
            a = parentArr[a][i];
        }
    }

    if (a == b)
    {
        return a;
    }

    // 2) 둘이 같을 때, 위에서부터 내려오며 공통 조상을 찾는다
    for (int i = LOGN - 1; i >= 0; i--) 
    {
        if (parentArr[a][i] != parentArr[b][i]) 
        {
            a = parentArr[a][i];
            b = parentArr[b][i];
        }
    }
    // 3) 바로 위가 LCA
    return parentArr[a][0];
}

// 두 노드 거리 계산
long long getDist(int a, int b) 
{
    int c = LCA(a, b);

    return depthArr[a] + depthArr[b] - 2LL * depthArr[c];
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> Q;
    // 초기 상태: 노드 1개 (노드번호 1)
    // 1번 노드의 레벨, 거리(depth)는 0으로
    levelArr[1] = 0;
    depthArr[1] = 0;

    for (int k = 0; k < LOGN; k++) 
    {
        parentArr[1][k] = 1;  // 편의상 자기 자신 가리키게
    }

    // 지름의 양 끝점. (초기엔 노드가 1개뿐이므로 L=R=1, 지름=0)
    int L = 1, R = 1;
    long long diameter = 0LL;

    // 각 쿼리를 처리하면서 노드를 하나씩 추가
    for (int i = 1; i <= Q; i++) 
    {
        int p;         // 연결할 부모 노드 q_i
        long long w;   // 간선 가중치 w_i
        cin >> p >> w;

        int newNode = i + 1;  // 이번에 새로 추가되는 노드 번호
        // newNode의 1단계 조상 설정
        parentArr[newNode][0] = p;
        // 레벨 = 부모 레벨 + 1(간선 하나 위로)
        levelArr[newNode] = levelArr[p] + 1;
        // 루트(1)~newNode까지의 가중치 누적
        depthArr[newNode] = depthArr[p] + w;

        // LCA 테이블 갱신
        for (int k = 1; k < LOGN; k++)
        {
            parentArr[newNode][k] = parentArr[parentArr[newNode][k - 1]][k - 1];
        }

        // 이제 지름 후보 계산
        long long dLR = getDist(L, R);
        long long dLX = getDist(L, newNode);
        long long dRX = getDist(R, newNode);

        // 새 지름 후보
        long long newDiameter = dLR;  // 일단 기존 지름
        // 만약 dLX가 더 크면 갱신
        if (dLX > newDiameter)
        {
            newDiameter = dLX;
        }
        // dRX가 더 크면 갱신
        if (dRX > newDiameter)
        {
            newDiameter = dRX;
        }

        // 만약 갱신이 있다면, 어떤 거리로 갱신됐는지 보고 L,R 교체
        // (동일 최대값이 여러 개여도 아무거나 택해도 무방)
        if (newDiameter == dLX && newDiameter > dLR) 
        {
            // (L, newNode)가 새 지름
            R = newNode;
        }
        else if (newDiameter == dRX && newDiameter > dLR) 
        {
            // (R, newNode)가 새 지름
            L = newNode;
        }

        diameter = newDiameter;

        // 출력
        cout << diameter << "\n";
    }

    return 0;
}
