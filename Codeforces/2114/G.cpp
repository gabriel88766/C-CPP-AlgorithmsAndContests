#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e5+3;
ll v[N];
ll adl[N], adr[N], psl[N], psr[N];
ll tt[N];

ll calc(ll a, ll b){
    ll x = a / b;
    while(x % 2 == 0) x /= 2;
    if(x != 1){
        int cnt = 1;
        int x = a;
        while(x % 2 == 0){
            x /= 2;
            cnt *= 2;
        }
        return cnt;
    }else{
        int cnt = 1;
        int x = a;
        while(x % 2 == 0){
            x /= 2;
            cnt *= 2;
        }
        int cnt2 = 1;
        x = 2*b;
        while(x % 2 == 0){
            x /= 2;
            cnt2 *= 2;
        }
        return cnt - cnt2 + 1;
    }
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        ll n, k;
        cin >> n >> k;
        for(int i=1;i<=n;i++){
            cin >> v[i];
        }
        for(int i=1;i<=n;i++){
            //calc max without adl adr.
            ll x = v[i];
            ll cnt = 1;
            while(x % 2 == 0){
                x /= 2;
                cnt *= 2;
            }
            tt[i] = cnt;
            //calc adr
            if(i == 1){
                adr[i] = tt[i]; //whatever, never happens
            }else{
                if(v[i] % v[i-1] == 0){
                    adr[i] = calc(v[i], v[i-1]);
                }else adr[i] = tt[i];
            }
            //calc adl
            if(i == n){
                adl[i] = tt[i]; //whatever, never happens
            }else{
                if(v[i] % v[i+1] == 0){
                    adl[i] = calc(v[i], v[i+1]);
                }else adl[i] = tt[i];
            }

        }
        for(int i=1;i<=n;i++){
            psr[i] = adr[i] + psr[i-1];
            psl[i] = adl[i] + psl[i-1];
        }
        ll mx = 0;
        for(int i=1;i<=n;i++){
            mx = max(mx, tt[i] + psl[i-1] + psr[n] - psr[i]);
        }
        if(mx >= k) cout << "YES\n";
        else cout << "NO\n";
    }
}