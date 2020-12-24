#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int32_t main() {
    ios::sync_with_stdio(0); 
    cin.tie(nullptr);

    /* if we sort the array, we can simply pass
     * for each index and update ans iff it is
     * different than the previous. (because 
     * in the sorted array, all equal elements
     * will be together)
     */

    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    int ans = 1; // we start with at least one distinct element
    for (int i = 1; i < n; i++) {
        if (a[i] != a[i-1]) ans++;
    }
    cout << ans << endl;

    return 0; 
}

