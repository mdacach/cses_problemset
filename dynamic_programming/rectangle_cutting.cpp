#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
const int N = 505;

int dp[N][N];

int solve(int a, int b) {
    if (a == b) return 0;
    if (dp[a][b]) return dp[a][b];
    // cut horizontally
    int m1 = 1e9;
    for (int i = 1; i < a; i++) {
        m1 = min(m1, solve(i, b) + solve(a - i, b));
    }
    // cut vertically
    int m2 = 1e9;
    for (int i = 1; i < b; i++) {
        m2 = min(m2, solve(a, i) + solve(a, b - i));
    }
    return dp[a][b] = min(m1, m2) + 1;
}


int32_t main() {
    ios::sync_with_stdio(0); 
    cin.tie(nullptr);

    int a, b;
    cin >> a >> b;
    cout << solve(a, b) << endl;

    return 0; 
}

