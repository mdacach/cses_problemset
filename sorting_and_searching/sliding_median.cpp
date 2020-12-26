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
    multiset<int, greater<int>> smaller;
    multiset<int> bigger;
    vector<int> aux(a);
    sort(aux.begin(), aux.begin() + k);
    for (int i = 0; i < k; i++) {
        if (i < (k + 1)/2) smaller.insert(aux[i]);
        else bigger.insert(aux[i]);
    }
    auto median = smaller.begin();
    cout << *median << " ";
    //cout.flush();
    for (int i = k; i < n; i++) {
        if (a[i] > *median) {
            bigger.insert(a[i]);
        } else {
            smaller.insert(a[i]);
        }
        if (a[i - k] > *median) {
            bigger.erase(bigger.find(a[i - k]));
        } else {
            smaller.erase(smaller.find(a[i - k]));
        }

        size_t sz = (k+1)/2;
        //cout << "sz = " << sz << endl;
        //cout << "smalelr sz = " << smaller.size() << endl;
        //cout.flush();
        while (smaller.size() > sz) {
            bigger.insert(*smaller.begin());
            smaller.erase(smaller.begin());
        }
        while (smaller.size() < sz) {
            smaller.insert(*bigger.begin());
            bigger.erase(bigger.begin());
        }
        assert(smaller.size() == sz);
        median = smaller.begin();
        cout << *median << " ";
        //cout.flush();
    }
    cout << endl;

    return 0; 
}

