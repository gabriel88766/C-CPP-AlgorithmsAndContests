#include <bits/stdc++.h>
typedef long long int ll;

using namespace std;

vector<ll> x;
vector<ll> k;

ll binpow(ll a, ll  b, ll  m){
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

ll divmod(ll a, ll b, ll m){
    return (a * binpow(b, m-2, m)) % m;
}

ll divmod2(ll a, ll b, ll m){
    return (a * binpow(b, 5e8+1, m)) % m;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    ll n, aux1, aux2, aux3 = 1, ans1 = 1, ans2 = 1, ans3 = 1, mod = 1e9+7;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> aux1 >> aux2;
        x.push_back(aux1);
        k.push_back(aux2);
        ans1 = (ans1 * (aux2 + 1)) % mod;
        aux3 = (aux3 * (aux2 + 1)) % (mod - 1);
        ans2 = ( ans2 * (binpow(aux1, aux2+1, mod) - 1)) % mod;
        ans2 = divmod(ans2, aux1 - 1, mod);
    }
    for(int i=0;i<n;i++){
        aux1 = (k[i] * (k[i] + 1))/2;
        aux2 = binpow(x[i], aux1, mod);
        aux1 = binpow(aux2, divmod2(aux3, k[i]+1, mod-1), mod);  
        ans3 = (aux1 * ans3) % mod;
    }
    cout << ans1 << " " << ans2 << " " << ans3;
}