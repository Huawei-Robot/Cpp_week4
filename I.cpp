#include <iostream> //´íÅÅ¹«Ê½
#include <vector>
using namespace std;
typedef long long ll;
const int maxn = 1001;
const int MOD = 1e9 + 7;
vector<vector <int> >combination(maxn, vector<int>(maxn, 0));
ll D[maxn];
void initCombination() {
	for (int i = 0; i <maxn; ++i) {
		combination[i][0]=1;
		for (int j = 1; j <= i; ++j) {
			combination[i][j] = (combination[i - 1][j - 1] + combination[i - 1][j]) % MOD;

		}
	}
}
void iniD() {
	D[0] = 1;
	D[1] = 0;
	D[2] = 1;
	for (int i = 3; i < maxn; ++i) {
		D[i] = (ll)(i - 1)*(D[i - 1] + D[i - 2])%MOD;
	}
}
int main() {
	int T;
	cin >> T;
	initCombination();
	iniD();
	int n, m, k;
	for (int kase = 1; kase <= T; ++kase) {
		cin >> n >> m >> k;
		ll ans=0;
		for (int i = 0; i <= n-m; ++i) {
			ans =(ans+ combination[n - m][i] * D[n - k - i])%MOD;
		}
		ans = ans * combination[m][k]%MOD;
		printf("Case %d: %lld\n", kase, ans);
	}
	return 0;
}