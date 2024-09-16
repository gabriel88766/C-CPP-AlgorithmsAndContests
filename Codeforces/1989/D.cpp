#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e6+3;
ll dp[N];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> vp(n);
    for(int i=0;i<n;i++) cin >> vp[i].first;
    for(int i=0;i<n;i++) cin >> vp[i].second;
    sort(vp.begin(), vp.end());
    int bst = INF_INT, p = 0;
    for(int i=1;i<N;i++){
        while(p < n && vp[p].first == i){
            bst = min(bst, vp[p].first - vp[p].second);
            p++;
        }
        if(bst != INF_INT){
            dp[i] = 2 + dp[i-bst];
        }
    }
    ll ans = 0;
    for(int i=0;i<m;i++){
        int x;
        cin >> x;
        if(x >= N){
            int q = (x-N)/bst + 1;
            ans += 2*q;
            x -= q*bst;
        }
        ans += dp[x];
    }
    cout << ans << "\n";
}
