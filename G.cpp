#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;
const int MAX = 2000000;  // n 和 k 最大为 10^6，所以 n + k - 1 最大为 2*10^6

vector<long long> factorial(MAX + 1);
vector<long long> invFactorial(MAX + 1);

// 快速幂计算
long long mod_pow(long long x, long long y, long long m) {
    long long res = 1;
    while (y > 0) {
        if (y % 2 == 1)
            res = res * x % m;
        x = x * x % m;
        y /= 2;
    }
    return res;
}

// 预处理阶乘和阶乘的逆元
void precompute_factorials() {
    factorial[0] = 1;
    for (int i = 1; i <= MAX; i++) {
        factorial[i] = factorial[i - 1] * i % MOD;
    }
    invFactorial[MAX] = mod_pow(factorial[MAX], MOD - 2, MOD);
    for (int i = MAX - 1; i >= 0; i--) {
        invFactorial[i] = invFactorial[i + 1] * (i + 1) % MOD;
    }
}

// 计算组合数 C(n, k)
long long combination(int n, int k) {
    if (n < k) return 0;
    return factorial[n] * invFactorial[k] % MOD * invFactorial[n - k] % MOD;
}

int main() {
    precompute_factorials();

    int T;
    cin >> T;
    for (int caseNum = 1; caseNum <= T; caseNum++) {
        int n, k;
        cin >> n >> k;
        long long result = combination(n + k - 1, k - 1);
        cout << "Case " << caseNum << ": " << result << endl;
    }

    return 0;
}
