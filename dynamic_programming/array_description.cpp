#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

const int N = 1e5 + 5;
const int MAX = 105;
const int mod = 1e9 + 7;

void add(int &a, int b) {
    a = (a + b < mod ? a + b : a + b - mod);
}

int dp[N][MAX];

int32_t main() {
    ios::sync_with_stdio(0); 
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> a(n+1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int x = 1; x <= m; x++) dp[1][x] = 1;

    for (int i = 1; i <= n; i++) {
        for (int x = 1; x <= m; x++) {
            if (a[i] != 0 and a[i] != x) continue;
            add(dp[i+1][x], dp[i][x]);
            add(dp[i+1][x+1], dp[i][x]);
            add(dp[i+1][x-1], dp[i][x]);
        }
    }

    if (a[n] != 0) cout << dp[n][a[n]] << endl;
    else {
        int ans = 0;
        for (int x = 1; x <= m; x++) {
            add(ans, dp[n][x]);
        }
        cout << ans << endl;
    }



    return 0; 
}

