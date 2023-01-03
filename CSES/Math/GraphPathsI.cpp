#include <bits/stdc++.h>
typedef long long int ll;
const ll MAX_LL = 0x3f3f3f3f3f3f3f3f;
const int MAX_INT = 0x3f3f3f3f;
using namespace std;

const ll MOD = 1e9+7;
int sizem = 100;
vector<vector<ll>> ans(105, vector<ll>(105));
vector<vector<ll>> aux(105, vector<ll>(105));
int cnt = 0;

void multMatrix(vector<vector<ll>> &a, vector<vector<ll>> b){
    for(ll i=0;i<sizem;i++){
        for(ll j=0;j<sizem;j++){
            aux[i][j] = 0;
            for(ll k=0;k<sizem;k++){
                aux[i][j] += a[i][k] * b[k][j];
                aux[i][j] %= MOD;
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
    for(ll i=0;i<sizem;i++) ans[i][i] = 1; //idt

    while(b > 0){
        if(b & 1) 
            multMatrix(ans, a);
        multMatrix(a, a);
        b >>= 1;
    }
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);

    ll n, m, k, a, b;
    cin >> n >> m >> k;
    sizem = n;
    vector<vector<ll>> v(n, vector<ll>(n));
    for(int i=0;i<m;i++){
        cin >> a >> b;
        v[a-1][b-1]++;
    }
    binpow(v, k);
    cout << ans[0][n-1];
    
}
 