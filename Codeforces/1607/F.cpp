#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2001;
char v[N][N];
char vis[N*N];
int adj[N*N], sz[N*N];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        for(int i=0;i<n*m;i++){
            vis[i] = sz[i] = 0;
        }
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin >> v[i][j];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int cur = i*m + j;
                int di = i, dj = j;
                if(v[i][j] == 'L') dj--;
                if(v[i][j] == 'R') dj++;
                if(v[i][j] == 'U') di--;
                if(v[i][j] == 'D') di++;
                if(di < 0 || di == n || dj < 0 || dj == m) adj[cur] = -1;
                else adj[cur] = di*m + dj;
            }
        }
        function<void(int)> dfs = [&](int u){
            stack<int> st;
            st.push(u);
            while(st.size() != 0){
                auto u = st.top();
                if(vis[u] == 0){
                    vis[u] = 1;
                    if(adj[u] == -1){
                        sz[u] = 1;
                    }else{
                        if(vis[adj[u]] == 2) sz[u] = sz[adj[u]] + 1;
                        else{
                            if(vis[adj[u]] == 1){
                                int cur = u;
                                vector<int> v;
                                do{
                                    v.push_back(cur);
                                    cur = adj[cur];
                                }while(cur != u);
                                for(auto x : v) sz[x] = v.size();
                            }else{
                                st.push(adj[u]);
                            }
                        }
                    }
                }else{
                    if(!sz[u]) sz[u] = sz[adj[u]] + 1;
                    vis[u] = 2;
                    st.pop();
                }
            }
        };



        for(int i=0;i<n*m;i++){
            if(!vis[i]) dfs(i);
        }
        pair<int,int> bst;
        int maxv = 0;
        for(int i=0;i<n*m;i++){
            if(sz[i] > maxv){
                maxv = sz[i];
                bst = {i/m, i%m};
            }
        }
        cout << bst.first+1 << " " << bst.second+1 << " " << maxv << "\n";

    }
}
