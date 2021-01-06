#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
const int MAX = 2e6 + 10;

int dp[MAX];

void init() {
    for (int i = 0; i < MAX; i++)
        dp[i] = 1e9;
}

int32_t main() {
    ios::sync_with_stdio(0); 
    cin.tie(nullptr);

    init();

    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (auto& c : coins) cin >> c;

    dp[0] = 0;
    for (int i = 0; i <= x; i++) {
        for (auto c : coins) {
            dp[i + c] = min(dp[i + c], dp[i] + 1);
        }
    }

    if (dp[x] == 1e9) cout << -1 << endl;
    else cout << dp[x] << endl;

    return 0; 
}

