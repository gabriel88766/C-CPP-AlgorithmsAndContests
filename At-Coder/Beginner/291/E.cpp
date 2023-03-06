#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
int indg[N], ans[N];
vector<int> adj[N];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    set<pair<int,int>> st;
    int n, m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        st.insert({a,b});
    }
    for(auto it = st.begin(); it != st.end(); ++it){
        adj[it->second].emplace_back(it->first);
        indg[it->first]++;
    }
    
    queue<int> q;
    for(int i=1;i<=n;i++) if(indg[i] == 0) q.push(i);
    vector<int> topo;
    int cnt = 0;
    while(!q.empty()){
        if(q.size() >= 2){
            break;
        }
        int u = q.front();
        q.pop();
        for(auto x : adj[u]){
            indg[x]--;
            if(indg[x] == 0) q.push(x);
        }
        ans[u] = n - cnt;
        cnt++;
    }
    if(cnt < n) cout << "No\n";
    else{
        cout << "Yes\n";
        for(int i=1;i<=n;i++) cout << ans[i] << " ";
    }
    
}
 