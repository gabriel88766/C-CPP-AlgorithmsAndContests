#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll cnt[2], summ[2];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    ll sum = 0;
    int n;
    cin >> n;
    cnt[0] = cnt[1] = 0;
    for(int i=1;i<=n;i++){
        ll aux;
        cin >> aux;
        summ[1] += aux; summ[0] += aux;
        int ind = i % 2;
        ll fac[2];
        fac[0] = fac[1] = 0;
        if(summ[ind] <= 0) {
            fac[ind] = 1 - summ[ind];
            summ[ind] = 1;
        }
        if(summ[ind^1] >= 0){
            fac[ind^1] = 1+summ[ind^1];
            summ[ind^1] = -1;
        }
        cnt[0] = cnt[0] + fac[0];
        cnt[1] = cnt[1] + fac[1];
    }

    cout << min(cnt[0], cnt[1]);
}
 