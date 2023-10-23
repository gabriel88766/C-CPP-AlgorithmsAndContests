#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
vector<int> mom[N];
vector<int> adj[N];
vector<int> adjt[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, t, k;
    cin >> n >> t;
    for(int i=1;i<=t;i++){
        int m;
        cin >> m;
        for(int j=1;j<=m;j++){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
            adjt[a].push_back(i);
            adjt[b].push_back(i);
        }
    }
    cin >> k;
    for(int i=1;i<=k;i++){
        int aux;
        cin >> aux;
        mom[aux].push_back(i);
    }
    vector<int> d(n+1, INF_INT);
    d[1] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, 1});
    while(!pq.empty()){
        auto dist = pq.top().first;
        auto u = pq.top().second;
        pq.pop();
        if(dist > d[u]) continue;
        for(int i = 0; i < adj[u].size(); i++){
            int nt = adjt[u][i];
            auto it = upper_bound(mom[nt].begin(), mom[nt].end(), dist);
            if(it == mom[nt].end()) continue;
            else if(d[adj[u][i]] > (*it)){
                d[adj[u][i]] = *it;
                pq.push({*it, adj[u][i]});
            }
        }
    }
    if(d[n] == INF_INT) cout << "-1\n";
    else cout  << d[n] << "\n";
}
