#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
const int MAX = 2e8 + 10;

int dp[MAX];

int32_t main() {
    ios::sync_with_stdio(0); 
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;
    vector<int> h(n);
    for (auto &z : h) cin >> z;
    vector<int> s(n);
    for (auto &z : s) cin >> z;

    for (int i = 0; i < n; i++) {
        for (int w = x; w >= 0; w--) {
            dp[w + h[i]] = max(dp[w + h[i]], dp[w] + s[i]);
        }
    }

    int ans = 0;
    for (int w = 0; w <= x; w++) ans = max(ans, dp[w]);
    cout << ans << endl;




    return 0; 
}

