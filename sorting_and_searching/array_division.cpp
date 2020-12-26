#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int32_t main() {
    ios::sync_with_stdio(0); 
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    auto valid = [&] (int64_t s) {
        //cout << "s = " << s << endl;
        int64_t cur = 0;
        int segs = 1;
        for (int i = 0; i < n; i++) {
            //cout << "i = " << i << endl;
            //cout << "remaining = " << n - i - 1 << endl;
            //cout << "segs agora = " << segs << endl;
            if (cur + a[i] > s) {
                segs++;
                cur = a[i];
                continue;
            }
            cur += a[i];
        }
        //cout << "segs = " << segs << endl;
        return segs <= k;
    };
    int64_t l = *max_element(a.begin(), a.end()), r = 1e18;
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
    cout << ans << endl;

    return 0; 
}

