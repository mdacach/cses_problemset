#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int32_t main() {
    ios::sync_with_stdio(0); 
    cin.tie(nullptr);

    /* precompute every sum we can get using
     * two elements
     * then, iterate over another two elements
     * and see if the remaining is there
     * NOTE: make sure to check if any element
     * was counted more than once
     *
     * better solution: 
     * create a new array with all the two-wise sums
     * do two pointers on that array to find the answer
     * 
     * probably passes:
     * O(n^3) with good constant
     * iterate over i, j, and then two pointers for the 
     * remaining elements
     */ 

    int64_t n, x;
    cin >> n >> x;
    vector<pair<int, int>> a;
    for (int i = 0; i < n; i++) {
        int t; cin >> t;
        a.push_back({t, i});
    }
    sort(a.begin(), a.end());
    map<int64_t, vector<pair<int, int>>> mp;
    for (int i = 0; i < n; i++) {
        auto [val1, ind1] = a[i];
        for (int j = i+1; j < n; j++) {
            auto [val2, ind2] = a[j];
            int64_t sum = a[i].first + a[j].first;
            mp[val1 + val2].push_back({ind1, ind2});
        }
    }


    auto ok = [] (int a, int b, int c, int d) {
        return (a != c and a != d and b != c and b != d);
    };

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            int64_t remaining = x - (a[i].first + a[j].first);
            for (auto [x, y] : mp[remaining]) {
                if (ok(x, y, a[i].second, a[j].second)) {
                    cout << a[i].second + 1 << " " << a[j].second + 1 << " ";
                    cout << x + 1 << " " << y + 1 << endl;
                    return 0;
                }
            }
        }
    }

    cout << "IMPOSSIBLE" << endl;


    return 0; 
}

