#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e5+3;
const int M = 102;
ll ps[M][N], ps2[M][N], aux[N], ans[N];
ll v[N];
 ll fat[N], invfat[N];
int n;
 
ll binpow(ll a, ll  b, ll  m){
    a %= m;
    ll ans = 1;
    while(b > 0){
        if(b & 1) ans = (ans * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return ans;
}
 
void init(){
    fat[0] = 1;
    for(int i=1;i<N;i++) fat[i] = (i * fat[i-1]) % MOD;
    for(int i=0;i<N;i++) invfat[i] = binpow(fat[i], MOD-2, MOD);
}
 
ll binomial(ll a, ll b){
    return (((fat[a]*invfat[a-b])%MOD)*invfat[b])%MOD;
}
 
 
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n, m;
    init();
    cin >> n >> m;
    vector<pair<int,pair<int,int>>> vp;
    for(int i=1;i<=n;i++) cin >> v[i];
    for(int i=0;i<m;i++){
        int l, r, x;
        cin >> l >> r >> x;
        ps[x][l] ++;
        ps[x][r+1] --;
        vp.push_back({x, {r+1, r-l}});
    }
    
    for(int j=99;j>=0;j--){
        for(int i=1;i<=n;i++){
            aux[i] = (aux[i] + ps[j+1][i] + aux[i-1])%MOD;
        }
        for(auto u : vp){
            if(u.first > j){
                aux[u.second.first] = (aux[u.second.first] +MOD- binomial(u.second.second+u.first-j, u.second.second))%MOD;
            }
        }
        
    }
    for(int i=1;i<=n;i++) ans[i] = (aux[i] + ans[i-1] + ps[0][i])%MOD;
    for(int i=1;i<=n;i++){
        cout << (v[i] + ans[i])%MOD << " ";
    }
}   
