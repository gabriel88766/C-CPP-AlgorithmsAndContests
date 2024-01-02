#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

vector<int> sts[20];
void init(){
    //all sets ok to test
    bitset<21> bs[21];
    for(int i=1;i<=19;i++){
        for(int j=i;j<=19;j+=i){
            bs[i][j] = 1;
        }
    }
    for(int i=5;i<=19;i++){
        for(int j=1;j<(1 << i); j++){
            bitset<21> aux;
            for(int k=0;k<i;k++){
                if(j & (1 << k)){
                    aux ^= bs[k+1];
                }
            }
            int cnt = 0;
            for(int k=1;k<=i;k++) if(aux[k] == 1) cnt++;
            if(cnt <= i/5) sts[i].push_back(j);
        }
    }
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    init();
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj(n+1);
        for(int i=1;i<=m;i++){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
        }
        if(n >= 20 || n == 15){
            cout << n << "\n";
            for(int i=1;i<=n;i++) cout << i << " ";
            cout << "\n";
            continue;
        }
        if(n <= 4){
            cout << "-1\n";
            continue;
        }
        vector<int> st(n+1);
        for(int i=1;i<=n;i++){
            vector<int> vis(n+1, false);
            queue<int> q;
            q.push(i);
            vis[i] = true;
            while(!q.empty()){
                auto u = q.front();
                q.pop();
                for(auto v : adj[u]){
                    if(!vis[v]){
                        q.push(v);
                        vis[v] = true;
                    }
                }
            }
            for(int j=0;j<n;j++){
                if(vis[j+1]) st[i] |= (1 << j);
            }
        }
        bool ok = false;
        for(auto x : sts[n]){
            int aux = 0;
            for(int j=0;j<n;j++){
                if((1 << j) & x){
                    aux |= st[j+1];
                }
            }
            if(aux == x){
                vector<int> ans;
                for(int j=0;j<n;j++){
                    if((1 << j) & x){
                        ans.push_back(j+1);
                    }
                }
                cout << ans.size() << "\n";
                for(auto x : ans) cout << x << " ";
                cout << "\n";
                ok = true;
                break;
            }
        }
        if(!ok) cout << "-1\n";
    }
}
