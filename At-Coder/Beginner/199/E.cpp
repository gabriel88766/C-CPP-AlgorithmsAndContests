#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

vector<pair<ll, ll>> rules[20];
ll dp[1 << 18];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    
    for(int i=1;i<=m;i++){
        ll x, y, z;
        cin >> x >> y >> z;
        rules[x].push_back({y, z});
    }
    dp[0] = 1;
    for(int i=1;i<(1 << n); i++){
        bool ok = true;
        for(auto [y, z] : rules[__builtin_popcount(i)]){
            int cnt = 0;
            for(int u=0;u<y;u++) if(i & (1 << u)) cnt++;
            if(cnt > z) ok = false;
        }
        
        if(!ok) continue;
        for(int j=0;j<n;j++){
            if(i & (1 << j)){
                dp[i] += dp[i ^ (1 << j)];
            }
        }
    }
    cout << dp[(1 << n) - 1] << "\n";
}
