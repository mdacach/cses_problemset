#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int32_t main() {
    ios::sync_with_stdio(0); 
    cin.tie(nullptr);

    /* standard two pointers problem.
     *
     * after we sort the array, we can keep
     * a pointer l to the smallest element and 
     * another pointer r to the biggest element
     *
     * at each step, we will try to sum a[l] + a[r]
     * if this sum is too big, decrease r
     * it it is too small, increase l
     *
     * NOTE: as we need to print the position of values,
     * we need to keep track of the original index 
     * (because sorting will mess it all)
     */

    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a[i] = {x, i};
    }
    sort(a.begin(), a.end());
    int l = 0, r = n-1;
    bool ok = false;
    while (l < r) {
        int sum = a[l].first + a[r].first;
        if (sum > x) r--;
        else if (sum < x) l++;
        else {
            ok = true;
            break;
        }
    }
    
    if (ok) cout << a[l].second + 1 << " " << a[r].second + 1 << endl;
    else cout << "IMPOSSIBLE" << endl;

    return 0; 
}

