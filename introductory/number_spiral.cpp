#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int32_t main() {
    ios::sync_with_stdio(0); 
    cin.tie(nullptr);

    // NOTE: swapping x, y for standard grid stuff

    /* first we need to go to the diagonal of max(x, y)
     * then, we will need to either climb up or climb left
     * depending on if (y > x)
     * as we climb, we will need to either sum abs(x - y) or subtract it
     * depending on the parity of the diag we started
     *
     * this works because the diagonal values are a Arithmetic Progression, 
     * and we can calculate them in constant time.
     *
     * S = 1 + 2 + 4 + 6 + 8
     * S = 8 + 6 + 4 + 2 + 1
     * 2*S = 9 + 8 + 8 + 8 + 9
     * 2*S = 8 * 5 + 2
     * S = (8 * 5 + 2) / 2
     * in general, for x terms and d the difference
     * Sx = ((x * a_x) + d) / 2
     */

    int t; cin >> t;
    while (t--) {
        int x, y;
        cin >> x >> y;
        int mx = max(x, y); // mx terms
        int64_t starting_value = 0LL; // this can get big
        int64_t last_term = 2 * (mx - 1); // a_x
        starting_value = (mx * last_term + 2) / 2;
        int64_t ans = 0LL;
        if (y > x) {
            // go up
            int64_t diff = y - x;
            if (mx % 2 == 0) ans = starting_value - diff;
            else ans = starting_value + diff;
        } else {
            // go left
            int64_t diff = x - y;
            if (mx % 2 == 0) ans = starting_value + diff;
            else ans = starting_value - diff;
        }

        cout << ans << endl;
    }

    return 0; 
}

