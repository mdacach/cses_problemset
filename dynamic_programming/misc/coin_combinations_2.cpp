#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
const int MAX = 1e6 + 1;
const int mod = 1e9 + 7;
const int N = 101;

int dp[N][MAX];

void add(int &a, int b) {
    a = (a + b < mod ? a + b : a + b - mod);
}

int32_t main() {
    ios::sync_with_stdio(0); 
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (auto& c : coins) cin >> c;

    dp[0][0] = 1;
    for (int i = 0; i <= x; i++) {
        for (int j = 0; j < n; j++) {
            int val = coins[j];
            if (i + val <= 1e6)
                add(dp[i+val][j], dp[i][j]);
            add(dp[i][j+1], dp[i][j]);
        }
    }

    cout << dp[n-1][x] << endl;

    return 0; 
}

