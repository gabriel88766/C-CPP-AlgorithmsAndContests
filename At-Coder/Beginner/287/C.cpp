#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
vector<int> adj[N];
bool visited[N];

void dfs(int u){
    visited[u] = true;
    for(auto i : adj[u]){
        if(!visited[i]){
            dfs(i);
        }
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n, m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    if(n != (m+1)){
        cout << "No";
        return 0;
    }
    dfs(1);
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
}
