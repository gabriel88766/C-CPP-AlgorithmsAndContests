#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+1;
int dp[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll n, l;
    cin >> n >> l;
    vector<ll> pm;
    for(ll i=1;i<l;i++){
        if(i * (l - i) < N ) pm.push_back(i * (l-i));
    }
    sort(pm.begin(), pm.end());
    pm.resize(unique(pm.begin(), pm.end()) - pm.begin());
    for(int i=1;i<N;i++) dp[i] = -1;
    for(int j=1; j<N;j++){
        for(auto x : pm){
            if(j - x >= 0 && dp[j-x] != -1) {
                if(dp[j] != -1) dp[j] = min(dp[j], dp[j-x] + 1);
                else dp[j] = dp[j-x] + 1;
            }
        }
    }
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        cout << dp[x] << "\n";
    }
}   
