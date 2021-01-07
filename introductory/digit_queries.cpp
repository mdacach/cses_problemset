#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int int64_t

int64_t pow(int64_t a, int64_t b) {
    int64_t res = 1;
    for (int i = 0; i < b; i++) res *= a;
    return res;
}

int ceil(int a, int b) {
    return (a + b - 1)/b;
}

int32_t main() {
    ios::sync_with_stdio(0); 
    //cin.tie(nullptr);

    int q; cin >> q;
    while (q--) {
        int64_t k; cin >> k;
        int64_t total = 0;
        int64_t power = 9;
        int64_t prv = 0;
        int digits = 1;
        for (int dd = 1; dd <= 18; dd++) {
            prv = total;
            total += 1LL * power * dd;
            if (total >= k) {
                digits = dd;
                break;
            }
            power *=  10;
        }
        //cout << log10(total) << " digits" << endl;
        assert(total >= k);
        //assert(total >= k);
        //cout << "prv = " << prv << endl;
        int64_t remaining = k - prv;
        //cout << "remaining = " << remaining << endl;
        //cout << "digits = " << digits << endl;
        //int cnt = ceil(remaining, digits);
        int cnt = remaining / digits;
        //cout << "cnt = " << cnt << endl;
        int start = pow(10, digits - 1);
        start = start + cnt - 1;
        //cout << "num = " << start << endl;
        int digit = remaining % digits;
        //cout << "digit = " << digit << endl;
        if (digit == 0) cout << start % 10 << endl;
        else {
            start++;
            cout << (start / (pow(int64_t(10), digits - digit))) % 10 << endl;
        }
        //cout << "digit = " << digit << endl;
        //for (int i = 0; i < digits - digit - 1; i++) start /= 10;
        //cout << start % 10 << endl;
        //cout << total << endl;
    }

    return 0; 
}

