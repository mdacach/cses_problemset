#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int32_t main() {
    ios::sync_with_stdio(0); 
    cin.tie(nullptr);

    /* we need to find an optimal distribution of 
     * the apartments. 
     *
     * let's sort both arrays, 
     * then for each apartment, find the first guy that accepts it
     * that way, other guys may still accept later apartments
     * and our distribution will not be compromised
     *
     * let's implement it using two pointers, 
     * which applicant we are considering and
     * which apartment we are considering
     * note that both pointers only move right 
     *
     * NOTE: we could probably do it with binary search too, but 
     * it would be messier I think
     */

    int n, m, k;
    cin >> n >> m >> k;
    vector<int> applicants(n), apartments(m);
    for (int i = 0; i < n; i++) cin >> applicants[i];
    for (int i = 0; i < m; i++) cin >> apartments[i];
    sort(applicants.begin(), applicants.end());
    sort(apartments.begin(), apartments.end());
    int cur_app = 0; // applicant we are considering now
    int cur_apt = 0; // apartmenet we are considering now
    int ans = 0;
    for (cur_apt = 0; cur_apt < m; cur_apt++) {
        while (cur_app < n and applicants[cur_app] < apartments[cur_apt] - k) {
            cur_app++;
        }
        if (cur_app == n) break; // did not find someone
        if (applicants[cur_app] <= apartments[cur_apt] + k) {
            // applicant inside range
            ans++;
            cur_app++;
        }
    }
    cout << ans << endl;

    return 0; 
}

