#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int32_t main() {
    ios::sync_with_stdio(0); 
    cin.tie(nullptr);

    /* standard sweep line problem.
     * make sure to sort arrival times
     * before leaving times if in a draw.
     */
    
    using event = pair<int, int>; // time, type
    int n; cin >> n;
    vector<event> events;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        events.push_back({a, -1}); // -1 for arrival so we can 
                                   // use standard sort for pairs
        events.push_back({b, 1});  // 1 for leaving
    }
    sort(events.begin(), events.end());
    int ans = 0, cnt = 0;
    for (auto [time, type] : events) {
        cnt -= type;
        ans = max(ans, cnt);
    }
    cout << ans << endl;

    return 0; 
}

