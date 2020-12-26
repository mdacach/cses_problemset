#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int32_t main() {
    ios::sync_with_stdio(0); 
    cin.tie(nullptr);

    int n; cin >> n;
    vector<int> a(n+1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<int64_t> p(n+1);
    for (int i = 1; i <= n; i++) p[i] = p[i-1] + a[i];
    map<int, int> mp; // remainder by n, quantity
    int64_t ans = 0;
    for (int i = 0; i <= n; i++) {
        int rmd = p[i] % n;
        if (rmd < 0) rmd += n;
        ans += mp[rmd];
        mp[rmd]++;
    }
    cout << ans << endl;
    

    return 0; 
}

