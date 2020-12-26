#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

struct movie {
    int start, end;
    bool operator< (const movie &other) const {
        if (end != other.end) return end < other.end;
        else return start > other.start;
    }
};

int32_t main() {
    ios::sync_with_stdio(0); 
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<movie> movies;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        movies.push_back({a, b});
    }
    sort(movies.begin(), movies.end());
    multiset<int> open;
    for (int i = 0; i < k; i++) open.insert(0);
    int ans = 0;
    for (auto [start, end] : movies) {
        auto it = open.upper_bound(start);
        if (it == open.begin()) continue;
        open.erase(prev(it));
        open.insert(end);
        ans++;
    }
    cout << ans << endl;

    return 0; 
}

