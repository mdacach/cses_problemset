#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int32_t main() {
    ios::sync_with_stdio(0); 
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> aux(a);
    sort(aux.begin(), aux.begin() + k);
    multiset<int, greater<int>> smaller;
    multiset<int> bigger;
    int64_t sum_smaller = 0, sum_bigger = 0;
    for (int i = 0; i < k; i++) {
        if (i < (k+1)/2) {
            smaller.insert(aux[i]);
            sum_smaller += aux[i];
        } else {
            bigger.insert(aux[i]);
            sum_bigger += aux[i];
        }
    }
    auto median = smaller.begin();
    auto get_cost = [&] (int64_t m) {
        int64_t res = 0;
        int sz1 = smaller.size();
        int sz2 = bigger.size();
        res += sz1 * m - sum_smaller;
        res += sum_bigger - sz2 * m;
        return res;
    };
    cout << get_cost(*median) << " ";
    for (int i = k; i < n; i++) {
        if (a[i] > *median) {
            bigger.insert(a[i]);
            sum_bigger += a[i];
        } else {
            smaller.insert(a[i]);
            sum_smaller += a[i];
        }
        if (a[i - k] > *median) {
            bigger.erase(bigger.find(a[i - k]));
            sum_bigger -= a[i - k];
        } else {
            smaller.erase(smaller.find(a[i - k]));
            sum_smaller -= a[i - k];
        }

        size_t sz = (k+1)/2;
        while (smaller.size() > sz) {
            sum_bigger += *smaller.begin();
            sum_smaller -= *smaller.begin();
            bigger.insert(*smaller.begin());
            smaller.erase(smaller.begin());
        }
        while (smaller.size() < sz) {
            sum_smaller += *bigger.begin();
            sum_bigger -= *bigger.begin();
            smaller.insert(*bigger.begin());
            bigger.erase(bigger.begin());
        }

        median = smaller.begin();
        cout << get_cost(*median) << " ";
    }
    cout << endl;



    return 0; 
}

