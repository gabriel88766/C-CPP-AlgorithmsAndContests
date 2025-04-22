#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

struct Allv{
    int mnpr, mxpr, mnsu, mxsu, sum;
};
int n, cnt;
const int N = 2e5+3, M = 20;
int vx[N], h[N];
int mxpr[N][M], mnpr[N][M], mxsu[N][M], mnsu[N][M], sum[N][M], mnmid[N][M], mxmid[N][M];
int anc[N][M];
void build(){
    for(int i=1;i<=cnt;i++){
        sum[i][0] = mxpr[i][0] = mxsu[i][0] = mxmid[i][0] = mnpr[i][0] = mnsu[i][0] = mnmid[i][0] = vx[i];
    }
    for(int j=1;j<M;j++){
        for(int i=1;i<=cnt;i++){
            anc[i][j] = anc[anc[i][j-1]][j-1];
            mxpr[i][j] = max(mxpr[i][j-1], sum[i][j-1] + mxpr[anc[i][j-1]][j-1]);
            mnpr[i][j] = min(mnpr[i][j-1], sum[i][j-1] + mnpr[anc[i][j-1]][j-1]);
            mxsu[i][j] = max(mxsu[anc[i][j-1]][j-1], mxsu[i][j-1] + sum[anc[i][j-1]][j-1]);
            mnsu[i][j] = min(mnsu[anc[i][j-1]][j-1], mnsu[i][j-1] + sum[anc[i][j-1]][j-1]);
            mnmid[i][j] = min({mnmid[i][j-1], mnmid[anc[i][j-1]][j-1], mnsu[i][j-1] + mnpr[anc[i][j-1]][j-1]});
            mxmid[i][j] = max({mxmid[i][j-1], mxmid[anc[i][j-1]][j-1], mxsu[i][j-1] + mxpr[anc[i][j-1]][j-1]});
            sum[i][j] = sum[i][j-1] + sum[anc[i][j-1]][j-1];
        }
    }
}

int lca(int a, int b){ 
    if(h[a] > h[b]) swap(a, b);
    int diff = h[b] - h[a];
    for(int i = M-1; i>=0;i--) if(diff & (1 << i)) b = anc[b][i];
    if(a == b) return a;
    for(int i= M-1;i >= 0;i--){
        while(anc[a][i] != anc[b][i]) a = anc[a][i], b = anc[b][i];
    }
    return anc[a][0];
}

vector<pair<int, int>> dolca(int a, int b){
    vector<pair<int, int>> ans;
    for(int j=M-1;j>=0;j--){
        if(h[a] - h[b] >= (1 << j)){
            ans.push_back({a, j});
            a = anc[a][j];
        }
    }
    return ans;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    vx[1] = 1;
    h[1] = 0;
    while(t--){
        cin >> n;
        vector<tuple<int, int, int>> qr;
        cnt = 1;
        for(int i=0;i<n;i++){
            char c;
            cin >> c;
            if(c == '?'){
                int u, v, k;
                cin >> u >> v >> k;
                qr.push_back({u, v, k});
            }else{
                int u, x;
                cin >> u >> x;
                cnt++;
                vx[cnt] = x;
                h[cnt] = h[u] + 1;
                anc[cnt][0] = u;
            }
        }
        build();
        //PAIN!!
        for(auto &[u, v, k] : qr){
            int lc = lca(u, v);
            auto a = dolca(u, lc);
            auto b = dolca(v, lc);
            reverse(b.begin(), b.end());
            vector<Allv> vn;
            int mn = 0, mx = 0;
            for(auto &[x, y] : a){
                vn.push_back({mnpr[x][y], mxpr[x][y], mnsu[x][y], mxsu[x][y], sum[x][y]});
                mn = min(mn, mnmid[x][y]);
                mx = max(mx, mxmid[x][y]);
            }
            mn = min(mn, vx[lc]);
            mx = max(mx, vx[lc]);
            vn.push_back({vx[lc], vx[lc], vx[lc], vx[lc], vx[lc]});
            for(auto &[x, y] : b){
                vn.push_back({mnsu[x][y], mxsu[x][y], mnpr[x][y], mxpr[x][y], sum[x][y]});
                mn = min(mn, mnmid[x][y]);
                mx = max(mx, mxmid[x][y]);
            }
            for(int i=0;i<vn.size();i++){
                int cs = 0;
                for(int j=i+1;j<vn.size();j++){
                    mn = min(mn, vn[j].mnpr + vn[i].mnsu + cs);
                    mx = max(mx, vn[j].mxpr + vn[i].mxsu + cs);
                    cs += vn[j].sum;
                }
            }
            if(k >= mn && k <= mx) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}
