#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int32_t main() {
    ios::sync_with_stdio(0); 
    cin.tie(nullptr);

    /* this is known as kadane algorithm. */

    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int64_t ans = INT64_MIN; // can't start with 0 (what if all numbers are negative?)
    int64_t cur_sum = 0;
    for (int i = 0; i < n; i++) {
        cur_sum += a[i];
        ans = max(ans, cur_sum);
        if (cur_sum < 0)  // does not make sense to keep this subarray
            cur_sum = 0;
    }
    cout << ans << endl;

    return 0; 
}

