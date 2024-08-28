#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>    //C(n,k)=C(n−1,k−1)+C(n−1,k) 杨辉三角
#include <vector>
using namespace std;
const int MOD = 1000007;
const int MAX = 1000;
vector<vector<int> >combination(MAX, vector<int>(MAX, 0));
void initCombination() {
	for (int i = 0; i < MAX; ++i) {
		combination[i][0] = 1;
		for (int j = 1; j <= i; ++j) {
			combination[i][j] = (combination[i - 1][j - 1] + combination[i - 1][j]) % MOD;
		}
	}
}
int main() {
	initCombination();
	int T;
	cin >> T;
	for (int i = 1; i <= T; ++i) {
		int M, N, K;
		cin >> M >> N >> K;
		if (K > M * N) {
			cout << "Case " << i << ": 0" << endl;
			continue;
		}
		int A = combination[M * N][K];
		int B = 0;
		if (K <= M * (N - 1))B = (B + combination[M * (N - 1)][K]) % MOD;
		if (K <= N * (M - 1))B = (B + combination[N * (M - 1)][K]) % MOD;
		B = (B << 1) % MOD;

		int C = 0;
		if (K <= M * (N - 2)) C = (C + combination[M * (N - 2)][K]) % MOD;
		if (K <= (M - 2) * N) C = (C + combination[(M - 2) * N][K]) % MOD;
		if (K <= (M - 1) * (N - 1)) C = (C + 4 * combination[(M - 1) * (N - 1)][K]) % MOD;

		int D = 0;
		if (K <= (M - 1) * (N - 2)) D = (D + combination[(M - 1) * (N - 2)][K]) % MOD;
		if (K <= (M - 2) * (N - 1)) D = (D + combination[(M - 2) * (N - 1)][K]) % MOD;
		D = (D << 1) % MOD;

		int E = 0;
		if (K <= (M - 2) * (N - 2)) E = combination[(M - 2) * (N - 2)][K];

		int ans = (A - B + C - D + E+ MOD) % MOD;


		cout << "Case " << i << ": " << ans << endl;
	}
	return 0;
}