#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

char grid[8][8];
bool cols[8], diag1[16], diag2[16];

int ans = 0;
void solve(int i) {
    if (i == 8) {
        ans++;
        return;
    } 
    for (int j = 0; j < 8; j++) {
        if (grid[i][j] == '*') continue;
        if (cols[j] || diag1[j-i+8-1] || diag2[i+j]) continue;
        cols[j] = diag1[j-i+8-1] = diag2[i+j] = true;
        solve(i+1);
        cols[j] = diag1[j-i+8-1] = diag2[i+j] = false;
    }
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> grid[i][j];
        }
    }

    solve(0);

    cout << ans << endl;


    return 0;
}

