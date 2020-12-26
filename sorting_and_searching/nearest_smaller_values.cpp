#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int32_t main() {
    ios::sync_with_stdio(0); 
    cin.tie(nullptr);

    /* key idea is: 
     * if we get to someone smaller, it is 
     * always better than someone bigger that 
     * came before it and we can "forget" this
     * bigger number from now on (so we do not
     * waste time passing through him again)
     */

    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    stack<pair<int, int>> st; // val, index
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        while (not st.empty() and st.top().first >= a[i]) {
            st.pop();
        }
        if (st.empty()) {
            ans[i] = 0;
        } else {
            ans[i] = st.top().second + 1;
        }
        st.push({a[i], i});
    }
    for (auto x : ans) cout << x << " ";
    cout << endl;

    return 0; 
}

