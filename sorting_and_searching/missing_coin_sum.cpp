#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int32_t main() {
    ios::sync_with_stdio(0); 
    cin.tie(nullptr);

    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    int64_t ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > ans+1) break;
        else ans += a[i];
    }

    cout << ans+1 << endl;


    return 0; 
}

