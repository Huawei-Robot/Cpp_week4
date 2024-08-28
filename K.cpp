#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>   //¿¨ÌØÀ¼Êý
#include <cstring>
using namespace std;
const int MAXN = 36;
long long c[MAXN];
void Catlan() {
	memset(c, 0, sizeof c);
	c[0] = c[1] = 1;
	for (int i = 2; i < MAXN; ++i) {
		for (int j = 0; j < i; ++j) {
			c[i] = c[i] + c[j] * c[i - j - 1];
		}
	}
}
int main() {
	Catlan();
	int n,t=1;
	while (cin >> n, n != -1) {
		cout << t++<<" " << n <<" " << 2 * c[n] << endl;
	}
	return 0;
}