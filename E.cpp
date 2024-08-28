#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
typedef long long ll;
const int maxn = 5e4 + 5;
ll phi[maxn];
void table() {
	memset(phi, 0, sizeof(phi));
	phi[1] = 1;
	for (int i = 2; i < maxn; i++) {
		if (phi[i] == 0) {
			for (int j = i; j < maxn; j += i) {
				if (phi[j] == 0) {
					phi[j] = j;
				}
				phi[j] = phi[j] / i * (i - 1);
			}
		}
	}
}
int main() {
	int n,ans;
	table();
	while (cin >> n, n) {
		ans = 0;
		for (int i = 2; i <= n; ++i) {
			ans += phi[i];
		}
		ans = ans * 2 + 1;
		cout << ans << endl;
	}
	return 0;
}