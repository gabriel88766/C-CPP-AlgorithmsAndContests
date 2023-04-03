#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e4+3;
int d[7][N];
vector<int> adj[N];
int n;

void bfs(int src, int p){
    for(int i=1;i<=n;i++) d[p][i] = INF_INT;
    queue<int> q;
    q.push(src); 
    d[p][src] = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto v : adj[u]){
            if(d[p][u] + 1 < d[p][v]){
                d[p][v] = d[p][u] + 1;
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
    int t;
    cin >> t;
    while(t--){
        int m, f, k;
        cin >> n >> m;
        for(int i=0;i<m;i++){
            int a,b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        cin >> f;
        vector<int> friends(f+1);
        for(int i=1;i<=f;i++) cin >> friends[i];
        cin >> k;
        vector<int> indx(k);
        for(int i=0;i<k;i++){
             cin >> indx[i];
             bfs(friends[indx[i]], i);
        }
        bfs(1, k);
        vector<vector<int>> pos(f+1);
        
        for(int i=1;i<=f;i++){
            bool cont = false;
            for(int j=0;j<k;j++) if(indx[j] == i) cont = true; //no car
            if(cont) continue;
            //has car
            int x = friends[i];
            for(int u=1;u< (1 << k); u++){
                vector<int> nowc;
                for(int v=0;v<k;v++){
                    if(u & (1 << v)) nowc.push_back(v);
                }
                do{
                    int curd = d[k][friends[indx[nowc[0]]]];
                    for(int j=0;j<nowc.size()-1;j++) curd += d[nowc[j]][friends[indx[nowc[j+1]]]];
                    curd += d[nowc[nowc.size()-1]][friends[i]];
                    if(curd == d[k][friends[i]]){
                        pos[i].push_back(u);
                        break;
                    }
                }while(next_permutation(nowc.begin(), nowc.end()));
            }
        }

        vector<bool> ans(1 << k, false);
        ans[0] = true;
        for(int i = 1;i<=f;i++){
            //has car
            vector<bool> aux(1 << k, false);
            for(int j=0;j<pos[i].size();j++){
                for(int w = 0;w < (1<<k);w++){
                    if(ans[w]) aux[w | pos[i][j]] = true;
                }
            }
            for(int w = 0;w < (1<<k);w++) if(ans[w]) aux[w] = true;
            ans = aux;
        }
        int ansv = k;
        for(int w=0; w < (1 << k); w++) if(ans[w]) ansv = min(ansv, k-__builtin_popcount(w));
        cout << ansv << "\n";
        for(int i=1;i<=n;i++) adj[i].clear();
    }
}
