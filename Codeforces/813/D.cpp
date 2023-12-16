#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 5005;
char adjc[N][N], adjf[N][N];
int src = 0, snk, n;

int bmf(vector<int> &par){
    queue<pair<int,int>> q;
    q.push({src, 0});
    vector<int> d(n+2, -INF_INT);
    d[0] = 0;
    while(!q.empty()){
        auto [u, dist] = q.front();
        q.pop();
        if(dist < d[u]) continue;
        for(int i=1;i<=n+1;i++){
            if(adjc[u][i] > adjf[u][i]){
                int s = adjc[u][i] > 0 ? 1 : -1;
                if(d[i] < d[u] + s){
                    d[i] = d[u] + s;
                    par[i] = u;
                    q.push({i, d[i]});
                }
            }
        }
    }
    return d[n+1] - 1;
}


int wtf(int k){
    int f = 0;
    vector<int> par(n+2);
    for(int i=0;i<k;i++){
        if(f == n) return n;
        int curf = bmf(par);
        f += curf;
        int cur = snk;
        while(cur != src){
            int p = par[cur];
            adjf[p][cur]++;
            adjf[cur][p]--;
            assert(adjc[p][cur] >= adjf[p][cur]);
            assert(adjc[cur][p] >= adjf[cur][p]);
            cur = p;
        }
    }
    return f;
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    cin >> n;
    snk = n+1;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++) cin >> v[i];
    for(int i=1;i<=n;i++){
        adjc[0][i] = 1;
        adjc[i][n+1] = 1;
        for(int j=i+1;j<=n;j++){
            if(abs(v[i]-v[j]) == 1 || v[i]%7 == v[j]%7){
                adjc[i][j] = 1;
            }
        }
    }
    cout << wtf(2);
}
