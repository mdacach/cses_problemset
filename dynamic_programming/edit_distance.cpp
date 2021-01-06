#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
const int N = 5005;

int dp[N][N];

int32_t main() {
    ios::sync_with_stdio(0); 
    cin.tie(nullptr);

    string s, t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    s = '*' + s;
    t = '*' + t;

    for (int i = 1; i <= n+1; i++) {
        for (int j = 1; j <= m+1; j++) {
            dp[i][j] = 1e9;
        }
    }

    dp[1][1] = 0;
    for (int i = 1; i <= n+1; i++) {
        for (int j = 1; j <= m+1; j++) {
            dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j] + (s[i] != t[j]));
            dp[i][j+1] = min(dp[i][j+1], dp[i][j] + 1);
            dp[i+1][j] = min(dp[i+1][j], dp[i][j] + 1);
        }
    }
    cout << dp[n+1][m+1] << endl;

    return 0; 
}

