#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    string s; cin >> s;
    sort(s.begin(), s.end());
    vector<string> ans;
    do {
        ans.push_back(s);
    } while (next_permutation(s.begin(), s.end()));

    cout << (int) ans.size() << endl;
    for (auto x : ans) cout << x << endl;

    return 0;
}

