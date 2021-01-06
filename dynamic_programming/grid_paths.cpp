#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
const int MAX = 1005;
const int mod = 1e9 + 7;

void add(int& a, int b) {
    a = (a + b < mod ? a + b : a + b - mod);
}

int dp[MAX][MAX];
char grid[MAX][MAX];

int32_t main() {
    ios::sync_with_stdio(0); 
    cin.tie(nullptr);

    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> grid[i][j];
        }
    }

    dp[1][1] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (grid[i][j] == '*') continue;
            add(dp[i+1][j], dp[i][j]);
            add(dp[i][j+1], dp[i][j]);
        }
    }

    if (grid[n][n] == '*') cout << 0 << endl;
    else  cout << dp[n][n] << endl;

    return 0; 
}

