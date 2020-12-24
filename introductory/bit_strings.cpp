#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

const int mod = 1e9 + 7;

int mul(int a, int b) {
    return (1LL * a * b) % mod;
}

// binary exponentiation
int fexp(int b, int e) {
    int res = 1;
    while (e) {
        if (e&1) res = mul(res, b);
        b = mul(b, b);
        e = (e >> 1);
    }
    return res;
}


int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int n; cin >> n;
    // two choices for each bit
    cout << fexp(2, n) << endl;



    return 0;
}

