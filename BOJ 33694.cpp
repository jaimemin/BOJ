#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
 
struct Event 
{
    ll day;
    ll delta;
};

bool cmp(Event a, Event b)
{
    if (a.day == b.day)
    {
        return a.delta < b.delta;
    }
    
    return a.day < b.day;
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    ll X;
    cin >> n >> X;
    
    vector<Event> events;
    events.reserve(2LL * n);
 
    for (int i = 0; i < n; i++)
    {
        ll A, B, C, T;
        cin >> A >> B >> C >> T;
 
        ll daysToReachC = (C + A - 1) / A;
        ll tR = T + daysToReachC;
        ll maxSize = A * (tR - T);
        
        if(maxSize < X) 
        {
            continue;
        }
        
        ll daysToReachX = (X + A - 1) / A;
        ll L = T + daysToReachX;
        ll extra = (maxSize - X) / B;
        ll R = tR + extra;
 
        if(L > R) 
        {
            continue;
        }
        
        events.push_back({L, 1});
        events.push_back({R + 1, -1});
    }
 
    if(events.empty())
    {
        cout << 0 << "\n";
        
        return 0;
    }
 
    sort(events.begin(), events.end(), cmp);
 
    ll currCount = 0;
    ll answer = 0;
    ll prevDay = events[0].day;
    int idx = 0;
    int sizeEvents = events.size();
 
    while(idx < sizeEvents)
    {
        ll currentDay = events[idx].day;

        if(currCount >= 3)
        {
            answer += (currentDay - prevDay);
        }

        while(idx < sizeEvents && events[idx].day == currentDay)
        {
            currCount += events[idx].delta;
            
            idx++;
        }
        
        prevDay = currentDay;
    }
 
    cout << answer << "\n";
    
    return 0;
}
