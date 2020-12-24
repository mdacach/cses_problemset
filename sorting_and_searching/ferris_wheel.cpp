#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int32_t main() {
    ios::sync_with_stdio(0); 
    cin.tie(nullptr);

    /* if we sort each child we can do two pointers
     * l = 0, r = n-1
     * try to put the smaller child with the biggest one possible
     * if it's not possible to put l with r, r must go alone
     * and we will try to find other one to go with l
     */
    
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    int ans = 0;
    for (int l = 0, r = n-1; l < n and r >= l; l++, r--) {
        while (r > l and a[l] + a[r] > x) {
            r--; ans++; // put this r kid alone
        }
        ans++; // put l and r together
    }

    cout << ans << endl;

    return 0; 
}

