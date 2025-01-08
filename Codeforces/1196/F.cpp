#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
const int M = 405;
bool vis[N];


ll adj[M][M];
ll dist[M][M];
int n;
void floyd(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dist[i][j] = INF_LL;
        }
    }
    for(int i=1;i<=n;i++) dist[i][i] = 0; 
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
        dist[i][j] = min(dist[i][j], adj[i][j]); //caution here
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(dist[i][k] < INF_LL && dist[k][j] < INF_LL)//for negative edge
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);    
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int g, m, k;
    cin >> g >> m >> k;
    vector<tuple<int,int,int>> vt(m);
    for(int i=0;i<m;i++){
        int a, b, w;
        cin >> a >> b >> w;
        vt[i] = {w, a, b};
    }
    sort(vt.begin(), vt.end());
    while(vt.size() > k) vt.pop_back();
    //vt.size() at most 400
    //total vertices at most 800
    //do many floyds in each connected subgraph, each has at most 401 vertices
    vector<int> allv;
    for(auto [w, a, b] : vt){
        allv.push_back(a);
        allv.push_back(b);
    }
    sort(allv.begin(), allv.end());
    allv.resize(unique(allv.begin(), allv.end()) - allv.begin());
    vector<ll> alld;
    for(auto x : allv){//800*400 naive bfs
        if(!vis[x]){
            vector<int> vx;
            vx.push_back(x);
            int p = 0;
            while(p < vx.size()){
                int x = vx[p];
                for(auto [w, a, b] : vt){
                    if(x == a && (!vis[b])){
                        vis[b] = true;
                        vx.push_back(b);
                    }else if(x == b && (!vis[a])){
                        vis[a] = true;
                        vx.push_back(a);
                    }
                }
                p++;
            }
            int aux = 0;
            map<int,int> mp;
            for(auto y : vx){
                mp[y] = ++aux;
            }
            n = vx.size();
            for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) adj[i][j] = INF_LL;
            for(auto [w, a, b] : vt){
                if(mp.count(a) && mp.count(b)){
                    adj[mp[a]][mp[b]] = adj[mp[b]][mp[a]] = w;
                }
            }
            floyd();
            for(int i=1;i<=n;i++){
                for(int j=i+1;j<=n;j++){
                    alld.push_back(dist[i][j]);
                }
            }
        }
    }
    sort(alld.begin(), alld.end());
    cout << alld[k-1] << "\n";
}
