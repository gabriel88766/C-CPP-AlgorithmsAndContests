#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
const int M = 800;
int val[M];
int dp[N];
int par[N];

void init(){
    for(int i=2;i<M;i++){
        val[i] = (i*(i-1))/2;
    }
    memset(dp, 63, sizeof(dp));
    dp[0] = 0;
    for(int j=2;j<M;j++){
        for(int i=0;i<N;i++){
            if(i+val[j] < N){
                if(dp[i+val[j]] >= dp[i] + j){
                    dp[i+val[j]] = dp[i]+j;
                    par[i+val[j]] = j;
                }
            }else break;
        }
    }
}

void solve(int p){
    cout << dp[p] << " ";
    vector<ll> x;
    int aux = p;
    while(aux){
        x.push_back(par[aux]);
        aux -= val[par[aux]];
    }
    ll ans = 0;
    for(int i=0;i<x.size();i++){
        for(int j=i+1;j<x.size();j++){
            ans += x[i]*x[j];
        }
    }
    cout << ans;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    init();
    int p;
    cin >> p;
    solve(p);
}
