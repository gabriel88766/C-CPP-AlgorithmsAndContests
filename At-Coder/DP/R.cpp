#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

vector<vector<ll>> multMatrix(vector<vector<ll>> a, vector<vector<ll>> b, ll m = MOD){
    int size = a.size();
    vector<vector<ll>> ans(size, vector<ll>(size));
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            ll cel = 0;
            for(int k=0;k<size;k++){
                cel = (cel + a[i][k] * b[k][j]) % MOD;
            }
            ans[i][j] = cel;
        }
    }
    return ans;
}

vector<vector<ll>> binpow(vector<vector<ll>> a, ll b, ll  m = MOD){
    int size = a.size();
    vector<vector<ll>> ans(size,vector<ll>(size)); //idt
    for(int i=0;i<size;i++) ans[i][i] = 1; //idt

    while(b > 0){
        if(b & 1) 
            ans = multMatrix(ans, a, m);
        a = multMatrix(a, a, m);
        b >>= 1;
    }
    return ans;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll n, k;
    cin >> n >> k;
    vector<vector<ll>> adj(n, vector<ll>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> adj[i][j];
        }
    }
    adj = binpow(adj, k);
    ll ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ans = (ans + adj[i][j]) % MOD;
        }
    }
    cout << ans;
}
