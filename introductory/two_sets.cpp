#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int n; cin >> n;

    int64_t sum = 1LL * n * (n + 1)/2;
    
    // if sum of 1 ... n is odd we can't ever split it
    if (sum&1) {
        cout << "NO" << endl;
        return 0;
    }

    // pick from ends until sum is correct
    // leftover is the other set
    int l = 1, r = n;
    vector<int> L, R;
    vector<int> a(n+1); // which set it is on
    int64_t cur_sum = 0;
    while (cur_sum + l + r <= sum/2) {
        cur_sum += l + r;
        a[l] = 1;
        a[r] = 1;
        l++;
        r--;
    }

    int left = sum/2 - cur_sum;
    if (left)
        a[left] = 1;

    for (int i = 1; i <= n; i++) {
        if (a[i]) L.push_back(i);
        else R.push_back(i);
    }

    cout << "YES" << endl;
    cout << int(L.size()) << endl;
    for (auto x : L) cout << x << " ";
    cout << endl;
    cout << int(R.size()) << endl;
    for (auto x : R) cout << x << " ";
    cout << endl;

    return 0;
}

