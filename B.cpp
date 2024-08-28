#include<iostream>
#include<vector>
#include <cstring>
using namespace std;
typedef long long ll;
const int MAX = 100000;
const int MAX_INTERVAL = 200000 + 100;
vector<int> prime; // 用于存储小于等于 sqrt(b) 的所有素数
bool not_prime[MAX]; // 用于标记非素数，大小为 MAX
bool interval[MAX_INTERVAL]; // 用于标记区间内的非素数，大小为 MAX_INTERVAL
void init() {
	for (int i = 2; i < MAX; i++) {
		if (not_prime[i])continue;
		prime.push_back(i);
		for (int j = i; j < MAX; j += i) {
			not_prime[j] = true;
		}
	}
}
int solve(ll a, ll b) {
    // 重置 interval 数组为 0（即假设所有数都是素数）
    memset(interval, 0, sizeof(interval));

    // 遍历所有已知的素数 prime
    for (int i = 0; i < prime.size(); i++) {
        // 如果 prime[i] 的平方大于 b，停止循环（因为更大的素数不需要再筛选）
        if ((ll)prime[i] * prime[i] > b) break;

        // 计算区间 [a, b] 内第一个 prime[i] 的倍数的位置
        ll s = (a + prime[i] - 1) / prime[i];
        // 如果 s 为 1，说明是 prime[i] 本身，这种情况不应该筛掉
        if (s < 2) s = 2;

        // 将 s 转换为区间内的实际值
        s *= prime[i];
        // 从 s 开始，将 prime[i] 的所有倍数标记为非素数
        for (; s <= b; s += prime[i]) {
            interval[s - a] = true; // 标记为非素数
        }
    }

    // 最后统计区间 [a, b] 内的素数个数
    int ans = 0;
    for (int i = 0; i <= b - a; i++) {
        if (!interval[i]) ans++; // 如果 interval[i] 为 false，则说明 i 是素数
    }
    return ans;
}
int main() {
	int T;
	cin >> T;
	init();
	for (int i = 1; i <= T; ++i) {
		ll a, b;
		cin >> a >> b;
        int ans = solve(a, b);
        if (a == 1)ans--;
        printf("Case %d: %d\n", i, ans);
	}
    return 0;
}