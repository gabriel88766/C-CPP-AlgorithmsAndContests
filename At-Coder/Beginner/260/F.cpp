#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 3005;
int lc[N][N];
vector<int> adj[300005];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int s, t, m;
    cin >> s >> t >> m;  
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    bool ok = false;
    for(int i=1;i<=s;i++) sort(adj[i].begin(), adj[i].end());
    for(int i=1;i<=s;i++){
        for(int j=0;j<adj[i].size();j++){
            for(int k=j+1;k<adj[i].size();k++){
                if(lc[adj[i][j]-s][adj[i][k]-s]){
                    ok = true;
                    cout << lc[adj[i][j]-s][adj[i][k]-s] << " " << adj[i][j] << " " << i << " " << adj[i][k] << "\n";
                    break;
                }else lc[adj[i][j]-s][adj[i][k]-s] = i;
            }
            if(ok) break;
        }
        if(ok) break;
    }
    if(!ok) cout << "-1\n";
}
