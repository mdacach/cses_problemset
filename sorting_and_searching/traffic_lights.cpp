#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int32_t main() {
    ios::sync_with_stdio(0); 
    cin.tie(nullptr);

    /* each new traffic light will divide a segment
     * int two
     * we can find the segment it divides with binary search
     * (if we keep segments ordered by start)
     * we also need to keep track of sizes of segments
     * to find the maximum one fast enough
     * so let's keep a set of segments and a multiset
     * of sizes, and remove and insert accordingly
     */

    int x, n;
    cin >> x >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    using seg = pair<int, int>;
    set<seg> segs;
    segs.insert({0, x});
    multiset<int, greater<int>> sizes;
    sizes.insert(x);
    for (auto t : a) {
        auto s = prev(segs.upper_bound({t, -1e9})); 
        auto [start, end] = *s;
        segs.erase(s);
        sizes.erase(sizes.find(end - start));
        segs.insert({start, t});
        segs.insert({t, end});
        sizes.insert(t - start);
        sizes.insert(end - t);
        cout << *sizes.begin() << " ";
    }
    cout << endl;

    return 0; 
}

