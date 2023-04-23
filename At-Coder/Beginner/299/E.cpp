#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2005;
vector<int> adj[N];
bool pos[N][N];
int d[N], c[N];

queue<int> q;
void bfs(){
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto v : adj[u]){
            if(d[u] + 1 < d[v]){
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int k;
    cin >> k;
    bool ok = true;
    vector<pair<int,int>> vp;
    for(int i=0;i<k;i++){
        int a,b;
        for(int j=1;j<=n;j++) pos[i][j] = true;
        cin >> a >> b;
        vp.push_back({a,b});
        memset(d, 63, sizeof(d)); q.push(a); d[a] = 0;
        bfs();
        for(int j=1;j<=n;j++) if(d[j] < b) pos[i][j] = false;
    }
    for(int i=1;i<=n;i++){
        bool ok2 = true;
        for(int j=0;j<k;j++){
            ok2 &= pos[j][i];
        }
        if(ok2) c[i] = 1;
    }
    memset(d, 63, sizeof(d));
    for(int i=1;i<=n;i++){
        if(c[i]){
            q.push(i);
            d[i] = 0;
        }
    }
    bfs();
    for(int i=0;i<k;i++){
        if(vp[i].second != d[vp[i].first]) ok = false;
    }
    if(ok){
        cout << "Yes\n";
        for(int i=1;i<=n;i++) cout << c[i];
    }else{
        cout << "No";
    }
}
