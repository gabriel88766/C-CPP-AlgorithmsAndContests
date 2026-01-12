#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


int dp[2][64];

int n;

void calc(int y, int mask, int nxt_mask){
    if(y == n){
        dp[1][nxt_mask] += dp[0][mask];
    }else{
        int cur = 1 << y;
        //2x1
        if(mask & cur){
            //cant 
            calc(y+1, mask, nxt_mask);
        }else{
            //can 1x2
            calc(y+1, mask, nxt_mask | cur);
            if(y+1 < n && !(mask & (cur << 1))){ // can 2x1
                calc(y+2, mask, nxt_mask);
            }
            calc(y+1, mask, nxt_mask);
        }
    }
}

vector<vector<ll>> multMatrix(vector<vector<ll>> a, vector<vector<ll>> b, ll m){
    int size = a.size();
    vector<vector<ll>> ans(size, vector<ll>(size));
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            ll cel = 0;
            for(int k=0;k<size;k++){
                cel = (cel + a[i][k] * b[k][j]) % m;
            }
            ans[i][j] = cel;
        }
    }
    return ans;
}

vector<vector<ll>> binpow(vector<vector<ll>> a, ll b, ll  m){
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
    ll h, w;
    cin >> h >> w;
    n = h;
    vector<vector<ll>> adj(1 << h, vector<ll>(1 << h));
    for(int i=0;i<(1<<h);i++){
        memset(dp, 0, sizeof(dp));
        dp[0][i] = 1;
        calc(0, i, 0);
        for(int j=0;j<(1<<h);j++){
            adj[i][j] = dp[1][j];
        }
    }
    adj = binpow(adj, w, MOD);
    cout << adj[0][0] << "\n";
}   
