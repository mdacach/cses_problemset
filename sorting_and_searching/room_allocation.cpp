#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int32_t main() {
    ios::sync_with_stdio(0); 
    cin.tie(nullptr);

    /* first part is a standard sweep line problem, 
     * how many rooms we'll need = how many segs intersect.
     *
     * after that, we have to find a way to distribute those 
     * rooms
     * I did it with another sweep line
     * keep track of available rooms
     * everytime some segment opens, assign a room
     * everytime some segment closes, put that room
     * back available
     */

    int n; cin >> n;
    using event = tuple<int, int, int>;
    vector<event> events;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        events.push_back({a, -1, i});
        events.push_back({b, 1, i});
    }
    sort(events.begin(), events.end());
    int cnt = 0;
    int total_rooms = 0;
    vector<int> ans(n);
    for (auto [time, type, id] : events) {
        cnt -= type;
        total_rooms = max(total_rooms, cnt);
    }
    set<int> open;
    for (int i = 1; i <= total_rooms; i++) 
        open.insert(i);
    for (auto [time, type, id] : events) {
        if (type == -1) {
            auto room = open.begin();
            ans[id] = *room;
            open.erase(room);
        } else {
            open.insert(ans[id]);
        }
    }
    cout << total_rooms << endl;
    for (auto x : ans) cout << x << " ";
    cout << endl;

    return 0; 
}

