#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 3e5+3;
int par[N], lc[N], rc[N], val[N];
map<pair<int,int>, int> tag;
set<pair<int,int>> nodes;
int cnt = 0;

void dfs(int u){
    if(lc[u]) dfs(lc[u]);
    if(rc[u]) dfs(rc[u]);
    if(u) cout << val[u] << " "; 
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n;
    cin >> n;
    //init
    lc[0] = 1;
    par[1] = 0;
    tag[{n, 1}] = ++cnt;
    nodes.insert({n, 1});
    vector<int> pr(n+1), in(n+1), invin(n+1);
    for(int i=1;i<=n;i++) cin >> pr[i];
    for(int i=1;i<=n;i++){
        cin >> in[i];
        invin[in[i]] = i;
    }

    for(int i=1;i<=n;i++){
        int place = invin[pr[i]];
        auto nxt = *nodes.lower_bound({place, 0});
        nodes.erase(nxt);
        if(nxt.first != nxt.second){
            int oldv = tag[nxt];
            int oldpar = par[oldv];

            int newv = ++cnt;
            val[newv] = pr[i];
            par[newv] = oldpar;
            tag[{place, place}] = newv;
            if(lc[oldpar] == oldv) lc[oldpar] = newv;
            else rc[oldpar] = newv;

            if((place - nxt.second) > 0){
                lc[newv] = ++cnt;
                par[cnt] = newv;
                pair<int,int> lchild = {place-1, nxt.second};
                tag[lchild] = cnt;
                nodes.insert(lchild);
            }
            if((nxt.first - place) > 0){
                rc[newv] = ++cnt;
                par[cnt] = newv;
                pair<int,int> rchild = {nxt.first, place+1};
                tag[rchild] = cnt;
                nodes.insert(rchild);
            }
        }else{
            val[tag[nxt]] = pr[i];
        }
    }
    dfs(0);


}
