#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e5+3;
vector<int> adj[N];
ll val[N];
ll dp1[N], dp2[N];
void solve(int u, int p){
    int ch = 0;
    ll sxt = 0;
    vector<ll> bst;
    for(auto v : adj[u]){
        if(v != p){
            ch++;
            solve(v, u);
            bst.push_back(dp1[v]);
            sxt += dp2[v];
        }
    }
    dp1[u] = 1;
    val[u] -= 1;
    if(ch == 0){
        dp2[u] = val[u];
    }else{
        sort(bst.begin(), bst.end(), greater<ll>());
        ll qt = min((ll)bst.size(), val[u]);
        for(int j=0;j<qt;j++) dp1[u] += bst[j] + 1;
        if(val[u] > qt){
            // cout << "here" << endl;
            dp1[u] += 2 * min(val[u] - qt, sxt);
            dp2[u] = val[u] - qt - min(val[u] - qt, sxt);
        }
    }
    // cout << u << " " << dp1[u] << " " << dp2[u] << "\n";
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    for(int i=1;i<=n;i++) cin >> val[i];
    for(int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int s;
    cin >> s;
    val[s]++;
    solve(s, 0);
    cout << dp1[s] - 1 << "\n";
}
