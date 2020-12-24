#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int32_t main() {
    ios::sync_with_stdio(0); 
    cin.tie(nullptr);

    /* two pointers
     *
     * for each l, starting at 0, let's find 
     * the maximum r such that no element repets.
     * let's call it R(l)
     * observe that R(i+1) >= R(i) for all i
     * so, we can just iterate from R(i-1) and onwards
     * (no need of a n^2 for)
     * 
     * to compute such R(i), let's maintain a set with
     * all elements that have already appeared
     * NOTE: remember to remove a[l] from the set when you increment l
     */

    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    set<int> seen;
    int ans = 0;
    for (int l = 0, r = 0; l < n; l++) {
        while (r < n and not seen.count(a[r])) {
            seen.insert(a[r]);
            r++;
        }

        ans = max(ans, r - l);
        if (r == n)  // this is the best we will get onward
            break;

        seen.erase(a[l]);
    }
    cout << ans << endl;



    return 0; 
}

