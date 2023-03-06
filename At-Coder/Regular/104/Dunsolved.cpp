//unsolved..
#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll MOD;
ll dp[81][441]; //sample
ll ans[11];

struct Upd{
    int i,j;
    ll val;
};

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n, k;
    n = 10, k = 8, MOD = 861271909; //sample 3
    dp[0][0] = 1;
    queue<Upd> upd;
    int cnt = 0;
    int maxs = (((1+n)*n)/2)*k;
    for(int i=1;i<=n;i++){
        for(int w=0;w<=(n*k);w++){
            for(int v=0;v<=maxs;v++){
                if(dp[w][v]){
                    Upd nup;
                    nup.i = w;
                    nup.j = v;
                    nup.val = dp[w][v];
                    upd.push(nup);
                }
            }
        }
        while(!upd.empty()){
            auto t = upd.front(); upd.pop();
            for(int j=1;j<=k;j++) dp[t.i+j][t.j+j*i] = (dp[t.i+j][t.j+j*i] + t.val) % MOD;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=(n*k);j++){
            if(i*j > maxs) break;
            ans[i] = (ans[i] + dp[j][j*i]) % MOD;
        }
        cout << ans[i] << "\n";
    }
}   
