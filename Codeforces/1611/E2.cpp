#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3, M = 20;
vector<int> adj[N];
vector<int> lvs;
int rt = 1, anc[N][M], h[N], sub[N], ord[N];
int n, cnt;

void dfs(int u, int par){ 
    anc[u][0] = par;
    h[u] = h[par] + 1;
    sub[u] = 1;
    ord[u] = ++cnt;
    bool lf = true;
    for(auto x : adj[u]){
        if(x != par){
            lf = false;
            dfs(x, u);
            sub[u] += sub[x];
        }
    } 
    if(lf) lvs.push_back(ord[u]);
}

void build(int n){
    h[0] = -1;
    dfs(rt, 0);
    for(int j = 1; j < M; j++){
        for(int i = 1; i <= n; i ++){
            anc[i][j] = anc[anc[i][j-1]][j-1];
        }
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        cnt = 0;
        int k;
        cin >> n >> k;
        vector<int> fr(k);
        for(int i=0;i<k;i++) cin >> fr[i];
        for(int i=1;i<n;i++){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        build(n);
        vector<pair<int,int>> vp;//{h, v}
        for(int i=0;i<k;i++){
            int hn = (h[fr[i]]+1)/2;
            int cur = fr[i];
            int dif = h[cur] - hn;
            assert(dif >= 0);
            for(int j=M-1;j>=0;j--) if(dif & (1 << j)) cur = anc[cur][j];
            vp.push_back({hn, cur});
        }
        sort(vp.begin(), vp.end());
        int ans = 0;
        vector<char> blkd(n+1, false);
        vector<char> isl(n+1, false);
        sort(lvs.begin(), lvs.end());
        for(auto x : lvs) isl[x] = true;
        for(auto [hn, cur] : vp){
            if(blkd[ord[cur]]) continue;
            else{
                auto it = lower_bound(lvs.begin(), lvs.end(), ord[cur]);
                if(it == lvs.end() || *it >= ord[cur] + sub[cur]) continue;
                ans++;
                for(int i=ord[cur];i<ord[cur]+sub[cur];i++) blkd[i] = true;
            }
        }
        bool ok = true;
        for(int i=1;i<=n;i++) if(!blkd[i] && isl[i]) ok = false;
        if(ok) cout << ans << "\n";
        else cout << "-1\n";

        for(int i=1;i<=n;i++) adj[i].clear();
        lvs.clear();
    }
}
