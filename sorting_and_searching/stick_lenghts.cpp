#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int32_t main() {
    ios::sync_with_stdio(0); 
    cin.tie(nullptr);

    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    auto cost = [&] (int64_t x) {
        int64_t res = 0;
        for (int i = 0; i < n; i++) 
            res += abs(a[i] - x);
        return res;
    };

    int x = 0;
    for (int b = 1e9; b >= 1; b /= 2) {
        //cout << "[x, b] = " << x << " " << b << endl;
        //cout << "cost1 = " << cost(x + b) << " cost2 = " << cost(x + b + 1) << endl;
        while (cost(x + b) > cost(x + b + 1)) {
            x += b;
            //cout << "cost1 = " << cost(x + b) << " cost2 = " << cost(x + b + 1) << endl;
        }
    }
    //cout << "ans x = " << x << endl;
    cout << cost(x+1) << endl;


    return 0; 
}

