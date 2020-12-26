#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int32_t main() {
    ios::sync_with_stdio(0); 
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;
    vector<int> a(n+1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<int64_t> p(n+1);
    for (int i = 1; i <= n; i++) p[i] = p[i-1] + a[i];
    set<int64_t> values;
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        if (values.count(p[i] - x)) {
            ans++;
        }
        values.insert(p[i]);
    }
    cout << ans << endl;


    return 0; 
}

