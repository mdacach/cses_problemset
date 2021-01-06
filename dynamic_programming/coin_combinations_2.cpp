#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

const int MAX = 2e6 + 10;
const int mod = 1e9 + 7;

void add(int& a, int b) {
    a = (a + b < mod ? a + b : a + b - mod);
}

int dp[MAX];

int32_t main() {
    ios::sync_with_stdio(0); 
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (auto &c : coins) cin >> c;
    dp[0] = 1;
    for (auto c : coins) {
        for (int i = 0; i <= x; i++) {
            add(dp[i+c], dp[i]);
        }
    }
    cout << dp[x] << endl;

    return 0; 
}

