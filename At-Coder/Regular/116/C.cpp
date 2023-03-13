#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 4e5+5;
int p[N]; // 0 if prime, 1 if not prime
vector<pair<ll,ll>> facts[N];
void sieve(){
    for(ll i=2; i<N; i++){
        if(!p[i]){
            for(ll j = i; j < N; j += i){
                p[j] = 1; 
                ll aux = j, cnt = 0;
                while(!(aux % i)){
                    cnt++;
                    aux /= i;
                }
                facts[j].emplace_back(i, cnt);
            }
        }
    }
}

ll fat[N], invfat[N];
void init(){ //MOD must be prime
    fat[0] = invfat[N-1] = 1;
    for(int i=1;i<N;i++){
        fat[i] = (fat[i-1]*i) % MOD;
    }
    ll aux = MOD - 2, aux2 = fat[N-1];
    while(aux){
        if(aux & 1) invfat[N-1] = (invfat[N-1] * aux2) % MOD;
        aux2 = (aux2 * aux2) % MOD;
        aux >>= 1;
    }
    for(int i=N-2;i>=0;i--) invfat[i] = (invfat[i+1] * (i + 1)) % MOD;
}
ll nCr(ll a, ll b){
    return (((fat[a] * invfat[a-b]) % MOD) * invfat[b]) % MOD;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    sieve();
    init();
    ll n, m;
    cin >> n >> m;
    ll ans = 1;
    for(ll i = 2;i<=m;i++){
        ll cur = 1;
        for(auto x: facts[i]){
            cur = (cur * nCr(x.second + n - 1, x.second)) % MOD;
        }
        ans = (ans + cur) % MOD;
    }
    
    cout << ans;
}
