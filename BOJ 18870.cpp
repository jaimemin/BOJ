#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;

    vector<int> coords(N);

    for (int i = 0; i < N; i++) 
    {
        cin >> coords[i];
    }

    // 복사본 생성 후 정렬
    vector<int> sortedCoords = coords;
    sort(sortedCoords.begin(), sortedCoords.end());

    // 중복 제거
    sortedCoords.erase(unique(sortedCoords.begin(), sortedCoords.end()), sortedCoords.end());

    // 좌표 압축 결과 매핑
    unordered_map<int, int> compression_map;

    for (int i = 0; i < sortedCoords.size(); i++) 
    {
        compression_map[sortedCoords[i]] = i;
    }

    // 결과 출력
    for (int i = 0; i < N; i++) 
    {
        cout << compression_map[coords[i]] << " ";
    }

    return 0;
}