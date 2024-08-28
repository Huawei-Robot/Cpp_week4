#include <iostream> //Â¬¿¨Ë¹¶¨Àí
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

typedef long long ll;

ll quick_mod(ll a, ll b, ll m) {
    ll ans = 1;
    a %= m;
    while (b) {
        if (b & 1)
            ans = ans * a % m;
        b >>= 1;
        a = a * a % m;
    }
    return ans;
}

ll getC(ll n, ll m, ll mod) {
    if (m > n)
        return 0;
    if (m > n - m)
        m = n - m;
    ll a = 1, b = 1;
    while (m) {
        a = (a * n) % mod;
        b = (b * m) % mod;
        m--;
        n--;
    }
    return a * quick_mod(b, mod - 2, mod) % mod;
}

ll Lucas(ll n, ll k, ll mod) {
    if (k == 0)
        return 1;
    return getC(n % mod, k % mod, mod) * Lucas(n / mod, k / mod, mod) % mod;
}

int main() {
    int T;
    cin>>T;
    while (T--) {
        ll n, m, mod;
        cin>>n>>m>>mod;
        printf("%lld\n", Lucas(n + m, m, mod));
    }
    return 0;
}
