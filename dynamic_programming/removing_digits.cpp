#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

const int MAX = 1e6;

int dp[MAX];

int32_t main() {
    ios::sync_with_stdio(0); 
    cin.tie(nullptr);

    int n; cin >> n;
    for (int i = 0; i <= n; i++) dp[i] = 1e9;
    dp[n] = 0;
    for (int i = n; i > 0; i--) {
        int val = i;
        while (val) {
            int d = val % 10;
            if (i - d >= 0) dp[i-d] = min(dp[i] + 1, dp[i-d]);
            val = val / 10;
        }
    }
    cout << dp[0] << endl;


    return 0; 
}

