#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<vector<int>> gr(n+1, vector<int>(n+1, -1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<n;j++){
            cin >> gr[i][j];
        }
    }
    vector<int> nc;
    vector<int> ptr(n+1, 1);
    for(int i=1;i<=n;i++) nc.push_back(i);
    int ans = 0;
    vector<bool> vis(n+1, false);
    while(nc.size()){
        ans++;
        vector<int> nnc;
        for(auto x : nc){
            if(vis[x]) continue;
            int u = gr[x][ptr[x]];
            if(vis[u]) continue;
            if(gr[u][ptr[u]] == x){
                vis[x] = vis[u] = true;
                ptr[u]++;
                ptr[x]++;
                if(ptr[u] != n) nnc.push_back(u);
                if(ptr[x] != n) nnc.push_back(x); 
            }
        }
        for(auto x : nnc) vis[x] = false;
        nc = nnc;
    }
    ptr[0] = n;
    if(*min_element(ptr.begin(), ptr.end()) == n) cout << ans << "\n";
    else cout << "-1\n";
}
