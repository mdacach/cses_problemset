#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int32_t main() {
    ios::sync_with_stdio(0); 
    cin.tie(nullptr);

    /* problem from the book (and good explanation there)
     *
     * it's always better to do the faster
     * tasks first
     * as rewards are linear, you do not 
     * lose much postponing a task if you
     * can do something better now
     */

    int n; cin >> n;
    using task = pair<int, int>;
    vector<task> a;
    for (int i = 0; i < n; i++) {
        int a_i, d_i;
        cin >> a_i >> d_i;
        a.push_back({a_i, d_i});
    }
    sort(a.begin(), a.end());
    int64_t ans = 0;
    int64_t time = 0;
    for (auto [a_i, d_i] : a) {
        time += a_i;
        ans += d_i - time;
    }
    cout << ans << endl;

    return 0; 
}

