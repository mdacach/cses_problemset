#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

string s;
void solve(int i, int n) {
    if (i == n) {
        cout << s << endl;
        return;
    }
    solve(i+1, n);
    s[i] = (s[i] == '1' ? '0' : '1');
    solve(i+1, n);
}

int32_t main() {
    ios::sync_with_stdio(0); 
    cin.tie(nullptr);

    int n; cin >> n;
    s = string(n, '0');
    //cout << s << endl;
    solve(0, n);

    return 0; 
}

