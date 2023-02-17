#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 5e5+3;
vector<int> adj[N];

int p[N], sz[N], cmp[N];
void init(){
    for(int i=1;i<N;i++) {p[i] = i; sz[i] = 1;}
}

int get(int a){ 
    return p[a] = (p[a] == a ? a : get(p[a]));
}

void unite(int a, int b){
    a = get(a);
    b = get(b);
    if(a == b) return;
    if(sz[a] < sz[b]) swap(a,b);
    p[b] = a;
    sz[a] += sz[b];
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n, m;
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        int a,b;
        cin >> a >> b;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    init();
    set<int> unv;
    for(int i=1;i<=n;i++) {
        sort(adj[i].begin(), adj[i].end());
        unv.insert(i);
    }
    for(int i=1;i<=n;i++){
        if(unv.count(i)){
            queue<int> q;
            q.push(i);
            unv.erase(i);
            while(!q.empty()){
                int u = q.front(); q.pop();
                int bp = 0;
                stack<int> rml;
                for(auto it = unv.begin(); it != unv.end(); ++it){
                    while(bp < adj[u].size() && adj[u][bp] < *it) bp++;
                    if(bp == adj[u].size() || adj[u][bp] != *it){
                        rml.push(*it);
                        q.push(*it);
                        unite(u, *it);
                    }
                }
                while(!rml.empty()) unv.erase(rml.top()), rml.pop();
            }
        }
    }
    
    vector<vector<int>> ans;
    int cnt = 1;
    for(int i=1;i<=n;i++){
        if(!cmp[get(i)]){
            cmp[get(i)] = cnt++;
            ans.emplace_back(vector<int> ());
            ans[cmp[get(i)]-1].emplace_back(i);
        }else ans[cmp[get(i)]-1].emplace_back(i);
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for(auto u : ans){
        cout << u.size() << " ";
        sort(u.begin(), u.end());
        for(auto x : u){
            cout << x << " ";
        }
        cout << "\n";
    }
    
    
}
