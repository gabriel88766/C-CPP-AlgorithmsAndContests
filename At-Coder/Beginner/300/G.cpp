#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

bool isp[101];
ll ans[101][(1 << 16) + 1];


ll solve(ll n, ll p){
    if(p == 2){
        return 64-__builtin_clzll(n);
    }
    if(n <= (1 << 16)) return ans[p][n];
    if(!isp[p]) return solve(n, p-1);
    ll ans = 0;
    for(ll j = 1; j <= n; j *= p){
        ans += solve(n/j, p-1);
    }
    return ans;
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    for(int i=2;i<=100;i++) isp[i] = true;
    vector<int> pr;
    for(int i=2;i<=100;i++){
        if(isp[i]){
            for(int j=2*i;j<=100;j+=i){
                isp[j] = false;
            }
            pr.push_back(i);
        }
    }

    for(int j=1;j<=(1 << 16); j++){
        int aux = j;
        int mxp = 1;
        for(auto p : pr){
            while(aux % p == 0){
                mxp = p;
                aux /= p;
            }
        }
        if(aux == 1) ans[mxp][j]++;
    }
    for(int i=1;i<=100;i++){
        for(int j=1;j<=(1 << 16);j++){
            ans[i][j] += ans[i][j-1];   
        }
    }
    for(int i=1;i<=100;i++){
        for(int j=1;j<=(1 << 16);j++){
            ans[i][j] += ans[i-1][j];
        }
    }


    ll n, p;
    cin >> n >> p;
    cout << solve(n, p) << "\n";
}
