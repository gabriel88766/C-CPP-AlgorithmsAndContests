#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll n, m;
    cin >> n >> m;
    if(n < 1000000){ // bruteforce
        if(n * n < m) cout << -1;
        else{
            ll minv = n*n;
            for(ll i=1;i<=n;i++){
                ll x = m/i;
                if(x * i < m) x++;
                if(x <= n) minv = min(minv, x*i);
            }
            cout << minv;
        }
    }else{
        ll minv = 1000000000000;
        for(ll i=1; i<=1000000;i++){
            ll x = m/i;
            if(x * i < m) x++;
            if(x <= n) minv = min(minv, x*i);
        }
        cout << minv;
    }
}
