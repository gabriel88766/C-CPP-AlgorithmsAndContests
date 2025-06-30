#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 305;
ll v[N];
bool adj[N][N];

pair<ll, ll> dist[N][N];
int n;
void floyd(){
    memset(dist, 63, sizeof(dist));
    for(int i=1;i<=n;i++) dist[i][i] = {v[i], 0}; 
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(adj[i][j] && i != j){
                dist[i][j] = {v[i] + v[j], 1};
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dist[i][k].second + dist[k][j].second < dist[i][j].second){
                    dist[i][j] = {dist[i][k].first + dist[k][j].first - v[k], dist[i][k].second + dist[k][j].second};
                }else if(dist[i][k].second  + dist[k][j].second == dist[i][j].second && dist[i][k].first + dist[k][j].first - v[k] > dist[i][j].first ){
                    dist[i][j] = {dist[i][k].first + dist[k][j].first - v[k], dist[i][j].second};
                }  
            }
        }
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    cin >> n;
    for(int i=1;i<=n;i++) cin >> v[i];
    for(int i=1;i<=n;i++){
        string s;
        cin >> s;
        s = " " + s;
        for(int j=1;j<=n;j++){
            if(s[j] == 'Y') adj[i][j] = true;
        }
    }
    floyd();
    int q;
    cin >> q;
    for(int i=1;i<=q;i++){
        int a, b;
        cin >> a >> b;
        if(dist[a][b].first != INF_LL) cout << dist[a][b].second << " " << dist[a][b].first << "\n";
        else cout << "Impossible\n";
    }
}   
