#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll fat[200005];
void init(){
    fat[0] = 1;
    for(int i=1;i<=200004;i++){
        fat[i] = (fat[i-1]*i) % MOD;
    }
}
ll binpow(ll a, ll b, ll m){
    a %= m;
    ll ans = 1;
    while(b > 0){
        if(b & 1) 
            ans = (ans * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return ans;
}

ll binnewton(ll a, ll b){
    ll ans = fat[a];
    ans = (ans * binpow(fat[b], MOD-2, MOD)) % MOD;
    ans = (ans * binpow(fat[a-b], MOD-2, MOD))% MOD;
    return ans;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    ll h,w,a,b;
    cin >> h >> w >> a >> b;
    ll sum = 0;
    init();

    for(int i=h-a;i<h;i++){
        // binnewton(w+h-i-b-1, w-b)
        sum = (sum + binnewton(i+b-1, i) *binnewton(w+h-i-b-2, w-b-1)) % MOD;
    }

    cout << (binnewton(h+w-2, h-1) + MOD - sum) % MOD;
}
