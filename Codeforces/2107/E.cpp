#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
ll mx[N];
vector<int> adj[N];
int solve(ll n, ll nn, ll k){
    assert(k >= -1);
    int rt = nn - (n - 1);
    if(n == 1) return rt;
    if(abs(k - mx[n-1]) <= 1 || k <= mx[n-1]){
        adj[rt].push_back(nn);
        solve(n-1, nn-1, k);
    }else{
        assert(mx[n] - k >= -1);
        solve(n-1, nn, k - (mx[n] - mx[n-1]));
        adj[rt].push_back(rt+1);
    }
    return rt;
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    mx[1] = 0;
    for(int i=2;i<N;i++){
        ll cur = i-1;
        cur *= (i-2);
        cur /= 2;
        mx[i] = mx[i-1] + cur;
    }
    int t;
    cin >> t;
    while(t--){
        ll n, k;
        cin >> n >> k;
        if(k == mx[n] + 1){
            cout << "Yes\n";
            for(int i=1;i<n;i++) cout << i << " " << i+1 << "\n";
        }else if(k <= mx[n]){
            cout << "Yes\n";
            solve(n, n, k);
            for(int i=1;i<=n;i++){
                for(auto &v : adj[i]){
                    if(v > i) cout << i << " " << v << "\n";
                }
            }
            for(int i=1;i<=n;i++) adj[i].clear();
            
        }else cout << "No\n";
    }
}
