#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

typedef long long LL;

// sqrt(2^31 - 1)
const int N = 1e6 + 10;

bool st[N];
int primes[N], cnt;

// ��ȡ����С�ڵ��� n ������
void getprime(int n) {
    memset(st, false, sizeof(st));
    cnt = 0;
    for (int i = 2; i < n; ++i) {
        if (!st[i]) primes[cnt++] = i;
        for (int j = 0; primes[j] <= n / i; ++j) {  // ��ֹ i * primes[j] > n
            st[i * primes[j]] = true;
            if (i % primes[j] == 0) break;
        }
    }
}

int main() {
    getprime(50000);
    int left, right, distance[N];
    while (cin >> left >> right) {
        memset(st, false, (right - left + 1) * sizeof(bool)); // ��ʼ������������

        for (int i = 0; i < cnt; ++i) {
            LL p = primes[i];
            for (LL j = max(2 * p, (left + p - 1) / p * p); j <= right; j += p) {
                st[j - left] = true; // ��Ǻ���
            }
        }

        cnt = 0;
        for (int i = 0; i <= right - left; ++i) {
            if (!st[i] && i + left > 1) {
                distance[cnt++] = i + left; // �洢����
            }
        }

        if (cnt < 2) {
            printf("There are no adjacent primes.\n");
        }
        else {
            int minp = 0, maxp = 0;
            for (int i = 0; i + 1 < cnt; ++i) {
                int d = distance[i + 1] - distance[i];
                if (d < distance[minp + 1] - distance[minp]) minp = i;
                if (d > distance[maxp + 1] - distance[maxp]) maxp = i;
            }
            printf("%d,%d are closest, %d,%d are most distant.\n",
                distance[minp], distance[minp + 1],
                distance[maxp], distance[maxp + 1]);
        }
    }
    return 0;
}
