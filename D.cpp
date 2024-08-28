#define _CRT_SECURE_NO_WARNINGS 1 //���ģ�a*b��%m=((a%m)(b%m))%m
#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
ll get_power(ll a, ll b, int M) {
    ll res = 1;
    a %= M; // a ȡģ M����ֹ���
    while (b > 0) {
        if (b & 1) { // ��� b ������
            res = (res * a) % M; // ���½����ȡģ
        }
        a = (a * a) % M; // a ƽ����ȡģ
        b >>= 1; // ����һλ���൱�� b ���� 2
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
                sum = (sum + get_power(a, b, M)) % M; // �ۼ�ÿ�� a^b % M ��ȡģ
            }
            cout << sum << endl; 
        }
    }
    return 0;
}
