#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e5 + 3;
vector<int> adj[N];
vector<int> inv[N];
int indg[N];
bool ok[N];
vector<int> ans;
vector<int> cur;

void dfs(int u){
    cur.push_back(u);
    for(auto v : inv[u]){
        if(!ok[v]){
            dfs(v);
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
        inv[b].push_back(a);
        indg[b]++;
    }
    for(int i=1;i<=n;i++){
        if(ok[i]) continue;
        dfs(i);
        stack<int> st;
        sort(cur.begin(), cur.end());
        for(int j=0;j<cur.size();j++){
            if(!indg[cur[j]]){
                ans.push_back(cur[j]);
                ok[cur[j]] = true;
                for(auto v : adj[cur[j]]) indg[v]--; 
            }else{
                st.push(cur[j]);
            }
            while(!st.empty()){
                int u = st.top();
                if(indg[u]) break;
                else{
                    ans.push_back(u);
                    ok[u] = true;
                    st.pop();
                    for(auto v : adj[u]) indg[v]--;
                }
            }
        }
        cur.clear();
    }
    for(auto x : ans) cout << x << " ";
    cout << "\n";
}
