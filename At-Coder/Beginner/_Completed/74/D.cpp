#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

struct Edge{
    ll a,b,v;
    Edge(ll a, ll b, ll v){
        this->a = a;
        this->b = b;
        this->v = v;
    }
    bool operator< (Edge ed){
        return v < ed.v;
    }
};

ll dist[305][305];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;  
    cin >> n;
    memset(dist, 63, sizeof(dist));
    vector<vector<ll>> v(n+1, vector<ll> (n+1, 0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> v[i][j];
        }
    }
    bool ok = true;
    vector<Edge> edgs;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            edgs.push_back(Edge(i,j, v[i][j]));
            for(int k=1;k<=n;k++){
                if(v[i][k] + v[k][j] < v[i][j]) ok = false;
            }
        }
    }
    for(int i=1;i<=n;i++) dist[i][i] = 0;

    sort(edgs.begin(), edgs.end());
    if(ok == false) cout << "-1";
    else{
        ll ans = 0;
        for(auto x : edgs){
            if(dist[x.a][x.b] > x.v){
                ans += x.v;
                dist[x.a][x.b] = dist[x.b][x.a] = x.v;
                for(int i=1;i<=n;i++){
                    for(int j=1;j<=n;j++){
                        dist[i][j] = dist[j][i] = \
                        min(dist[i][j], min(dist[i][x.a] + x.v + dist[x.b][j], \
                        dist[i][x.b]+x.v+dist[x.a][j]));
                    }
                }
            }
        }
        cout << ans;
    }
}
