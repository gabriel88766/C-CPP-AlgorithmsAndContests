#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+2;
ll v[N];
int n, k;
ll ans = 0;

void solve(ll val = 0, int idx = 0, int ch = 0){
    if(ch == k){
        ans = max(ans, val);
        return;
    }
    for(int i=idx+1;i<=n;i++){
        solve(val ^ v[i], i, ch+1);
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    cin >> n >> k;
    ll ps = 0;
    for(int i=1;i<=n;i++) cin >> v[i];
    for(int i=1;i<=n;i++) ps = ps ^ v[i];
    if(k > n-k){
        k = n-k;
        solve(ps);
    }else solve();
    cout << ans << "\n";
}
