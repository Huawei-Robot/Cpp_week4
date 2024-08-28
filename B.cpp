#include<iostream>
#include<vector>
#include <cstring>
using namespace std;
typedef long long ll;
const int MAX = 100000;
const int MAX_INTERVAL = 200000 + 100;
vector<int> prime; // ���ڴ洢С�ڵ��� sqrt(b) ����������
bool not_prime[MAX]; // ���ڱ�Ƿ���������СΪ MAX
bool interval[MAX_INTERVAL]; // ���ڱ�������ڵķ���������СΪ MAX_INTERVAL
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
    // ���� interval ����Ϊ 0������������������������
    memset(interval, 0, sizeof(interval));

    // ����������֪������ prime
    for (int i = 0; i < prime.size(); i++) {
        // ��� prime[i] ��ƽ������ b��ֹͣѭ������Ϊ�������������Ҫ��ɸѡ��
        if ((ll)prime[i] * prime[i] > b) break;

        // �������� [a, b] �ڵ�һ�� prime[i] �ı�����λ��
        ll s = (a + prime[i] - 1) / prime[i];
        // ��� s Ϊ 1��˵���� prime[i] �������������Ӧ��ɸ��
        if (s < 2) s = 2;

        // �� s ת��Ϊ�����ڵ�ʵ��ֵ
        s *= prime[i];
        // �� s ��ʼ���� prime[i] �����б������Ϊ������
        for (; s <= b; s += prime[i]) {
            interval[s - a] = true; // ���Ϊ������
        }
    }

    // ���ͳ������ [a, b] �ڵ���������
    int ans = 0;
    for (int i = 0; i <= b - a; i++) {
        if (!interval[i]) ans++; // ��� interval[i] Ϊ false����˵�� i ������
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