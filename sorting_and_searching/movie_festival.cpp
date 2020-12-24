#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int32_t main() {
    ios::sync_with_stdio(0); 
    cin.tie(nullptr);

    /* after we sort the movies by ending times, we
     * can greedily pick an optimal solution.
     * (as explained in the book)
     */

    int n; cin >> n;
    using movie = pair<int, int>; // start time, end time
    vector<movie> movies;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        movies.push_back({a, b});
    }
    auto cmp = [&] (movie a, movie b) {
        if (a.second != b.second) return a.second < b.second;
        else return a.first < b.first;
    };
    sort(movies.begin(), movies.end(), cmp);
    int ans = 0;
    int nxt = 0; // next time available
    for (auto [start, end] : movies) {
        if (start >= nxt) {
            ans++;
            nxt = end;
        }
    }
    cout << ans << endl;

    return 0; 
}

