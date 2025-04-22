#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

void bfs(int u, vector<ll> &d, vector<vector<int>> &adj){
    d[u] = 0;
    queue<int> q;
    q.push(u);
    while(!q.empty()){
        auto u = q.front();
        q.pop();
        for(auto &v : adj[u]){
            if(d[v] > d[u] + 1){
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }    
}

vector<ll> process_tree(){
    int n;
    cin >> n;
    vector<vector<int>> adj(n+1);
    for(int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<ll> d1(n+1, INF_INT), d2(n+1, INF_INT), ans(n+1);
    bfs(1, d1, adj);
    int ft1 = max_element(d1.begin()+1, d1.end()) - d1.begin();
    fill(d1.begin(), d1.end(), INF_INT);
    bfs(ft1, d1, adj);
    int ft2 = max_element(d1.begin()+1, d1.end()) - d1.begin();
    bfs(ft2, d2, adj);
    for(int i=1;i<=n;i++){
        ans[i] = max(d1[i], d2[i]);
    }
    ans[0] = INF_INT;
    return ans;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    auto d1 = process_tree();
    auto d2 = process_tree();
    int md = max(*max_element(d1.begin()+1, d1.end()), *max_element(d2.begin()+1, d2.end()));
    int n1 = d1.size() - 1;
    int n2 = d2.size() - 1;
    sort(d1.begin(), d1.end());
    sort(d2.begin(), d2.end());
    vector<ll> ps(d2.size());
    for(int i=0;i<d2.size();i++){
        ps[i] = d2[i];
        if(i != 0) ps[i] += ps[i-1];
    }
    ull ans = 0;
    for(int i=0;i<n1;i++){
        if(d1[i] + d2[0] + 1 >= md){
            ans += d1[i] * n2 + ps[n2-1] + n2;
        }else{
            ll x = n2;
            for(int j = n2;j>=1;j>>=1){
                while(x - j >= 0 && d1[i] + d2[x-j] + 1 >= md) x -= j;
            }
            assert(x > 0);
            ans += (n2-x) * d1[i] + ps[n2-1] - ps[x-1] + (n2-x);
            ans += md * x;
        }
    }
    cout << ans << "\n";
}
