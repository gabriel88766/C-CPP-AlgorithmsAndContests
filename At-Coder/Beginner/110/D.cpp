#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 100030;
ll fat[N], invfat[N];
ll k, n;
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
    cin >> k >> n;
    init();
    vector<pair<ll,ll>> facts;
    ll aux2 = n;
    for(ll i = 2; i*i <= n; i++){
        ll aux = 1, cnt = 0;
        while(!(aux2%(aux*i))) aux *= i, cnt++;
        if(cnt){
            facts.push_back({i, cnt});
        }
        aux2 /= aux;
    }
    if(aux2 != 1) facts.push_back({aux2,1});
    
    ll ans = 1;
    for(auto x : facts){
        ans = (ans * nCr(k+x.second-1, x.second)) % MOD;
    }
    cout << ans;
}
