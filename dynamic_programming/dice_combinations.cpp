#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
const int N = 1e6 + 10;
const int mod = 1e9 + 7;

int dp[N];

int32_t main() {
    ios::sync_with_stdio(0); 
    cin.tie(nullptr);

    int n; cin >> n;
    dp[0] = 1;
    for (int x = 0; x <= n; x++) {
        for (int d = 1; d <= 6; d++) {
            dp[x + d] += dp[x];
            dp[x + d] %= mod;
        }
    }
    cout << dp[n] << endl;

    return 0; 
}

