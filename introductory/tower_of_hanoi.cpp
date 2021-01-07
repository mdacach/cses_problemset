#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

void solve(int n, int orig, int dest, int mid) {
    if (n == 1) {
        cout << orig << " " << dest << endl;
        return;
    }
    solve(n-1, orig, mid, dest);
    cout << orig << " " << dest << endl;
    solve(n-1, mid, dest, orig);
}

int32_t main() {
    ios::sync_with_stdio(0); 
    cin.tie(nullptr);

    int n; cin >> n;
    cout << (1 << n) - 1 << endl;
    solve(n, 1, 3, 2);
    

    return 0; 
}

