#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 105;
int adj[N][N];
int dist[N][N];
int n;
void floyd(){
    memset(dist, 63, sizeof(dist));
    for(int i=0;i<n;i++){ for(int j=0;j<n;j++){ if(adj[i][j]) dist[i][j] = 1;}}
    for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);    
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int  k;
    cin >> n >> k;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin >> adj[i][j];
    int q;
    cin >> q;
    floyd();
    for(int i=0;i<q;i++){
        ll a,b;
        cin >> a >> b;
        ll ra = (a-1)%n, rb = (b-1)%n;
        if(dist[ra][rb] != INF_INT) cout << dist[ra][rb] << "\n";
        else cout << "-1\n";
    }
}
