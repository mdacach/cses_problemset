#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int32_t main() {
    ios::sync_with_stdio(0); 
    cin.tie(nullptr);

    int n, a, b;
    cin >> n >> a >> b;
    vector<int> vec(n+1);
    for (int i = 1; i <= n; i++) cin >> vec[i];
    vector<int64_t> p(n+1);
    for (int i = 1; i <= n; i++) p[i] = p[i-1] + vec[i];
    multiset<int64_t> s;
    for (int i = 0; i < a; i++) s.insert(p[i]);
    int64_t ans = 0;
    for (int i = a; i <= n; i++) {
        ans = max(ans, p[i] - *s.begin());
        s.erase(s.find(p[i - a]));
        s.insert(p[i]);
    }
    cout << ans << endl;


    return 0; 
}

