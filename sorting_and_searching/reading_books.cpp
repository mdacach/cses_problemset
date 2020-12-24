#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int32_t main() {
    ios::sync_with_stdio(0); 
    cin.tie(nullptr);

    /* the optimal strategy for reading is
     * one starts with the biggest book and 
     * then continues with the small
     * while the other starts with the small
     *
     * we can see that one pointer will always
     * be behind the other, unless the sum of 
     * all small books < biggest
     * in that case, we will need to wait their
     * difference no matter what
     */

    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    int64_t total = accumulate(a.begin(), a.end(), 0LL);
    cout << max(total, int64_t(2LL * a.back())) << endl;

    return 0; 
}

