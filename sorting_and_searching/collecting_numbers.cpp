#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int32_t main() {
    ios::sync_with_stdio(0); 
    cin.tie(nullptr);

    int n; cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a[i] = {x, i};
    }
    sort(a.begin(), a.end());
    int ans = 1;
    int last = 0;
    for (auto [x, id] : a) {
        if (id < last) ans++;
        last = id;
    }
    cout << ans << endl;

    return 0; 
}

