#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int bof[2001];
ll dp[2001];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    sort(v.begin(), v.end());
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        if(a <= k) bof[a] = max(bof[a], b);
    }
    v.resize(k);
    sort(v.begin(), v.end(), greater<int>());
    vector<ll> ps(k+1, 0);
    for(int i=0;i<k;i++) ps[i+1] = ps[i] + v[i];
    memset(dp, 63, sizeof(dp));
    dp[0] = 0;
    for(int i=1;i<=k;i++){
        for(int j=0;j<i;j++){
            ll cost = ps[i]-ps[j] - (ps[i] - ps[i-bof[i-j]]);
            dp[i] = min(dp[i], dp[j]+cost);
        }
    }
    cout << dp[k];
}
