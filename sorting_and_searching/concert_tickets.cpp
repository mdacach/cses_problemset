#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int32_t main() {
    ios::sync_with_stdio(0); 
    cin.tie(nullptr);

    /* sort the tickets by price
     * for each customer, we can find the nearest 
     * ticket with upperbound (-1), then
     * remove this ticket from the list
     *
     * we can use a multiset to implements this
     */
    
    int n, m;
    cin >> n >> m;
    multiset<int> tickets;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        tickets.insert(x);
    }
    vector<int> a(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }
    for (auto value : a) {
        auto it = tickets.upper_bound(value);
        if (it == tickets.begin()) {
            // no ticket is available
            cout << -1 << endl;
        } else {
            auto ticket = prev(it);
            cout << *ticket << endl;
            tickets.erase(ticket);
        }
    }


    return 0; 
}

