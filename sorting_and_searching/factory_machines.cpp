#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int32_t main() {
    ios::sync_with_stdio(0); 
    cin.tie(nullptr);

    /* basically the problem from the book
     *
     * if we fix a time t, the optimal way
     * is to make every machine work together
     * then, machine i will produce floor(t, k_i)
     * items
     * if the sum of those items >= what we need, 
     * we can do it with time t
     * note that if we can make all items at a time
     * t1, we can make also for all times t2 > t1
     * then, we can binary search for the first time
     * that works
     * NOTE: deal with overflows (even for int64_t (ll))
     */

    int n, t;
    cin >> n >> t;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    auto valid = [&] (int64_t time) {
        __int128_t res = 0; // also works 
        // NOTE: int128_t does not support cin or cout
        // this works because I know that ans will be int64_t 
        for (auto x : a) {
            res += time / x;
            // otherwise check for overflow here
            // if (res >= t) break;
        }
        return res >= t;
    };

    int64_t l = 0, r = 1e18;
    int64_t ans = -1;
    while (l <= r) {
        int64_t m = l + (r - l) / 2;
        if (valid(m)) {
            ans = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    assert(ans != -1);
    cout << ans << endl;

    return 0; 
}

