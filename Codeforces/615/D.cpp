#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int cnt[200005];

ll binpow(ll a, ll b, ll m = MOD){
    a %= m;
    ll ans = 1;
    while(b > 0){
        if(b & 1) ans = (ans * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return ans;
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int m;
    cin >> m;
    for(int i=0;i<m;i++){
        int aux;
        cin >> aux;
        cnt[aux]++;
    }
    ll n = 1, ans = 1;
    ll ndiv = 1; //hard part..
    bool h2 = false;
    for(int i=2;i<=200000;i++){
        if(cnt[i]%2 && !h2){
            h2 = true;
            ndiv = (ndiv * (cnt[i]+1)/2) % (MOD-1);
        }else ndiv = (ndiv * (cnt[i]+1)) % (MOD - 1);
    }
    
    
    for(ll i=2;i<=200000;i++){
        if(cnt[i]){
            int maxi;
            if(h2) maxi = cnt[i];
            else maxi = cnt[i]/2;
            for(int j=1;j<=maxi;j++){
                n = (n * i) % MOD;
            }
        }
    }
    cout << binpow(n, ndiv);
    
    
}
