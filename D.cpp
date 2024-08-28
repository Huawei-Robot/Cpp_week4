#define _CRT_SECURE_NO_WARNINGS 1 //核心（a*b）%m=((a%m)(b%m))%m
#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
ll get_power(ll a, ll b, int M) {
    ll res = 1;
    a %= M; // a 取模 M，防止溢出
    while (b > 0) {
        if (b & 1) { // 如果 b 是奇数
            res = (res * a) % M; // 更新结果并取模
        }
        a = (a * a) % M; // a 平方并取模
        b >>= 1; // 右移一位，相当于 b 除以 2
    }
    return res;
}

int main() {
    int T, t, M;
    ll a, b;
    while (cin >> T && T != 0) { 
        while (T--) {
            ll sum = 0;
            cin >> M; 
            cin >> t; 
            while (t--) {
                cin >> a >> b; 
                sum = (sum + get_power(a, b, M)) % M; // 累加每个 a^b % M 并取模
            }
            cout << sum << endl; 
        }
    }
    return 0;
}
