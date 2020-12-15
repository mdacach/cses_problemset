#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int N; cin >> N;
    for (int n = 1; n <= N; n++) {
        // total ways of putting two knights is 
        // total squares choose two
        int64_t total_squares = 1LL * n * n;
        int64_t total_ways = total_squares * (total_squares - 1)/2;
        // ways of putting two knights that DO attack each other
        // this always forms a 2x3 or 3x2 rectangle, so we can count
        // this instead
        // 2x3: 
        // for each possible row we can choose (n - 2) squares
        // there are (n - 1) possible rows
        // 3x2 case is analogous
        // for each rectangle, we can permute the order of knights
        // so each rectangle should count twice
        // thus, we have 4 * (n - 1) * (n - 2) ways 
        //
        // answer is total - this ways
        int64_t attack_ways = 4 * (n - 1) * (n - 2);
        int64_t ans = total_ways - attack_ways;
        cout << ans << endl;
    }



    return 0;
}

