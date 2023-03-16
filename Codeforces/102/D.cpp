#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
ll dp[N];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;

    vector<int> cd = {-1, 0};
    dp[0] = 0, dp[1] = 1;
    vector<pair<ll,ll>> par;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        cd.push_back(b);
        par.push_back({b,a});
    }
    sort(cd.begin(), cd.end());
    cd.resize(unique(cd.begin(), cd.end()) - cd.begin());
    

    sort(par.begin(), par.end());
    int last = -1;
    for(int i=0;i<m;i++){
        int ind = lower_bound(cd.begin(), cd.end(), par[i].second) - cd.begin();
        int ind2 = lower_bound(cd.begin(), cd.end(), par[i].first) - cd.begin();
        if(ind) --ind;
        ll val = dp[ind2-1] - dp[ind] + MOD;
        if(last != par[i].first) dp[ind2] = dp[ind2-1];
        last = par[i].first;
        dp[ind2] = (dp[ind2] + val) % MOD;
    }
    if(cd.back() == n){
         cout << (dp[cd.size()-1] - dp[cd.size()-2] + MOD)%MOD;
    }
    else cout << 0;
}
