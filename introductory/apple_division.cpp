#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    int64_t ans = 1e18;
    int64_t total = accumulate(a.begin(), a.end(), 0LL);
    for (int b = 0; b < (1 << n); b++) {
        int64_t cur = 0;
        for (int i = 0; i < n; i++) {
            if (b & (1 << i)) cur += a[i];
        }
        ans = min(ans, abs(cur - (total-cur)));
    }

    cout << ans << endl;

    return 0;
}

