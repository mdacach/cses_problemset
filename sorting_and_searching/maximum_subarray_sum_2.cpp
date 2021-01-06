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
    //cout << "pref: ";
    //for (int i = 0; i <= n; i++) cout << p[i] << " ";
    //cout << endl;
    multiset<int64_t> s;
    int64_t ans = -1e18;
    for (int i = a; i <= n; i++) {
        //cout << "pra i = " << i << " set: ";
        s.insert(p[i-a]);
        //for (auto x : s) cout << x << " ";
        //cout << endl;
        ans = max(ans, p[i] - *s.begin());
        //cout << "ans aqui = " << p[i] - *s.begin() << endl;
        if (i - b >= 0) s.erase(s.find(p[i-b]));
    }
    cout << ans << endl;


    return 0; 
}

