#define _CRT_SECURE_NO_WARNINGS 1 //指数循环节
#include <iostream>
#include<algorithm>
#include <cstring>
using namespace std;
const int maxm = 10001;
const int maxn = 15;
int phi[maxm + 1];
void init(int n) {   //求2-n的欧拉函数值
	memset(phi,0,sizeof phi);
	phi[1] = 1;
	for (int i = 2; i <= n; ++i) {
		if (!phi[i]) {
			for(int j = i; j <= n; j+=i) {
				if (!phi[j])phi[j] = j;
				phi[j] = phi[j] / i * (i - 1);
			}
		}
	}
}
int pow_mod(int x, int y, int mod) {   //快速幂
	int ret = 1;
	x = x % mod;
	while (y > 0) {
		if (y & 1) {
			ret = (ret * x)%mod;
		}
		x = (x * x)%mod;
		y >>= 1;
	}
	return ret;
}
int e[maxn], n;
void dfs(int pos,int mod) {
	if (pos < n - 2)dfs(pos + 1, phi[mod]);
	e[pos] = pow_mod(e[pos], e[pos+1] % phi[mod] + phi[mod], mod);

}
int main() {
	init(maxm);
	int mod, counts = 0;
	while (cin >> mod) {
		cin >> n;
		for (int i = 0; i < n; ++i)cin >> e[i];
		if (n > 1) {
			dfs(0, mod);
		}
		else {
			e[0] %= mod;
		}
		printf("Case #%d: %d\n", ++counts, e[0]);
	}
	return 0;
}
