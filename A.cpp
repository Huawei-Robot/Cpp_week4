#include <iostream>
using namespace std;
typedef long long ll;
ll countships(ll a, ll b) {
    ll counts = 0;
    while (a!=0&&b!=0)
    {
        
        if (b > a) {
            swap(a, b);
        }
        counts += a/b;
        ll temp = a % b;
        a = b;
        b = temp;
    }
    return counts;
}
int main()
{
    ll a, b,counts=0;
    cin >> a >> b;
    counts = countships(a, b);
    cout << counts << endl;
    return 0;
}
