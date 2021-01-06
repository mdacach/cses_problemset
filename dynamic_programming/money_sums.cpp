#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int32_t main() {
    ios::sync_with_stdio(0); 
    cin.tie(nullptr);

    int n; cin >> n;
    vector<int> coins(n+1);
    for (int i = 1; i <= n; i++) cin >> coins[i];

    int sum = accumulate(coins.begin(), coins.end(), 0);

    //vector<int> possible(sum+1);

    bitset<int(1e6)> possible;
    possible[0] = 1;
    for (int c : coins) {
        possible |= (possible << c);
    }

    int total = 0;
    for (int x = 1; x <= sum; x++) total += possible[x];
    cout << total << endl;
    for (int x = 1; x <= sum; x++) {
        if (possible[x]) cout << x << " ";
    }
    cout << endl;
    

    return 0; 
}

