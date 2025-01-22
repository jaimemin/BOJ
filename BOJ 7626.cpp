#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Event
{
    int x, y1, y2, type;

    Event(int x, int y1, int y2, int type) : x(x), y1(y1), y2(y2), type(type) {}

    bool operator<(Event& e) 
    {
        return x < e.x;
    }
};

vector<int> v;

vector<long long> length;

vector<int> coords;

void updateLength(int node, int start, int end) 
{
    if (v[node] > 0) 
    {
        length[node] = coords[end + 1] - coords[start];

        return;
    }
    
    if (start == end)
    {
        length[node] = 0;
    }
    else
    {
        length[node] = length[node * 2] + length[node * 2 + 1];
    }
}

void update(int node, int start, int end, int left, int right, int value) 
{
    if (end < left || start > right)
    {
        return;
    }

    if (left <= start && end <= right) 
    {
        v[node] += value;
        updateLength(node, start, end);

        return;
    }

    int mid = (start + end) / 2;
    update(node * 2, start, mid, left, right, value);
    update(node * 2 + 1, mid + 1, end, left, right, value);
    updateLength(node, start, end);
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;

    vector<Event> events;
    vector<int> yCoords;

    for (int i = 0; i < N; i++)
    {
        int x1, x2, y1, y2;
        cin >> x1 >> x2 >> y1 >> y2;

        events.emplace_back(x1, y1, y2, 1); // 시작 이벤트
        events.emplace_back(x2, y1, y2, -1); // 끝 이벤트
        yCoords.push_back(y1);
        yCoords.push_back(y2);
    }

    // y좌표 압축
    sort(yCoords.begin(), yCoords.end());
    yCoords.erase(unique(yCoords.begin(), yCoords.end()), yCoords.end());
    coords = yCoords;

    // 세그먼트 트리 배열 초기화
    int n = coords.size();
    v.resize(n * 4);
    length.resize(n * 4);

    // 이벤트 정렬
    sort(events.begin(), events.end());

    long long area = 0;
    int prevX = events[0].x;

    for (auto event : events) 
    {
        int x = event.x;
        int y1 = lower_bound(coords.begin(), coords.end(), event.y1) - coords.begin();
        int y2 = lower_bound(coords.begin(), coords.end(), event.y2) - coords.begin();
        int type = event.type;

        // 면적 계산
        area += length[1] * (x - prevX);
        prevX = x;

        // 세그먼트 트리 갱신
        update(1, 0, coords.size() - 2, y1, y2 - 1, type);
    }

    cout << area << '\n';

    return 0;
}