#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int32_t main() {
    ios::sync_with_stdio(0); 
    cin.tie(nullptr);

    /* iterate over i, j and then 
     * binary search for the remaining 
     * quantity.
     * we could also do it with two pointers,
     * iterate over i and then two pointers just
     * like two sum to find if there's the remaining
     * sum
     */

    int n, x;
    cin >> n >> x;
    vector<pair<int64_t, int>> a(n);
    for (int i = 0; i < n; i++) {
        int val; cin >> val;
        a[i] = {val, i};
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            int64_t sum = a[i].first + a[j].first;
            int64_t remaining = x - sum;
            auto it = lower_bound(a.begin(), a.end(), make_pair(remaining, -1)) - a.begin();
            while (it < n and (a[it].second == a[i].second or a[it].second == a[j].second)) it++;
            if (it < n and a[it].first == remaining) {
                cout << a[i].second + 1 << " " << a[j].second + 1 << " " << a[it].second + 1 << endl;
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;


    return 0; 
}

