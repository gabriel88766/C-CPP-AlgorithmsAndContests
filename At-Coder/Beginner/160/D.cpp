#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2005;
vector<int> adj[N];
int d[N][N];
int tt[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, x, y;
    cin >> n >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
    for(int i=1;i<n;i++){
        adj[i].push_back(i+1);
        adj[i+1].push_back(i);
    }
    memset(d, 63, sizeof(d));
    for(int i=1;i<=n;i++){
        d[i][i] = 0;
        queue<int> q;
        q.push(i);
        while(q.size()){
            int u = q.front();
            q.pop();
            for(auto v : adj[u]){
                if(d[i][v] > d[i][u] + 1){
                    d[i][v] = d[i][u] + 1;
                    q.push(v);
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            tt[d[i][j]]++;
        }
    }
    for(int i=1;i<=n-1;i++){
        cout << tt[i] << "\n";
    }
}
