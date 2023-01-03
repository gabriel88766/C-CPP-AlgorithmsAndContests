#include <bits/stdc++.h>
typedef long long int ll;
const ll MAX_LL = 0x3f3f3f3f3f3f3f3f;
const int MAX_INT = 0x3f3f3f3f;
using namespace std;

const ll MOD = 1e9+7;
int sizem = 100;
vector<vector<ll>> ans(105, vector<ll>(105));
vector<vector<ll>> aux(105, vector<ll>(105));

void multMatrix(vector<vector<ll>> &a, vector<vector<ll>> b){
    for(ll i=0;i<sizem;i++){
        for(ll j=0;j<sizem;j++){
            aux[i][j] = MAX_LL;
            for(ll k=0;k<sizem;k++){
                aux[i][j] = min(aux[i][j], a[i][k] + b[k][j]);
            }
        }
    }
    for(int i=0;i<sizem;i++){
        for(int j=0;j<sizem;j++){
            a[i][j] = aux[i][j];
        }
    }
}

void binpow(vector<vector<ll>> a, ll b){
    for(ll i=0;i<sizem;i++){
        for(ll j=0;j<sizem;j++){
            if(i == j) ans[i][j] = 0;
            else ans[i][j] = MAX_LL;
        }
    }

    while(b > 0){
        if(b & 1) 
            multMatrix(ans, a);
        multMatrix(a, a);
        b >>= 1;
    }
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    ll n, m, k, a, b, w;
    cin >> n >> m >> k;
    sizem = n;
    vector<vector<ll>> v(n, vector<ll>(n, MAX_LL));
    for(int i=0;i<m;i++){
        cin >> a >> b >> w;
        v[a-1][b-1] = min(v[a-1][b-1], w); //multi-edge
    }
    binpow(v, k);
    if(ans [0][n-1] < MAX_LL) cout << ans[0][n-1];
    else cout << -1;
    
}
 