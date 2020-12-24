#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int32_t main() {
    ios::sync_with_stdio(0); 
    cin.tie(nullptr);

    /* as we put them in the given order, 
     * there's no reason to create a new 
     * tower if we can put it into an 
     * existent one
     *
     * that being said, it's best if we put 
     * the new cube on the smallest tower 
     * possible. that way, we do not block
     * any next cubes
     */
    
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    multiset<int> s;
    for (int i = 0; i < n; i++) {
        auto tower = s.upper_bound(a[i]);
        if (tower != s.end()) {
            s.erase(tower);
        }
        s.insert(a[i]);
    }
    cout << int(s.size()) << endl;

    return 0; 
}

