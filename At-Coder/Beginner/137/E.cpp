#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2505;
ll dist[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m, p;
    cin >> n >> m >> p;
    vector<tuple<int, int, int>> edg;
    for(int i=1;i<=m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        c -= p;
        edg.push_back({a, b, c});
    }
    for(int i=2;i<=n;i++) dist[i] = -INF_INT;
    for(int i=1;i<=n;i++){
        for(auto &[a, b, c] : edg){
            if(a == b && c > 0 && dist[a] != -INF_INT) dist[a] = INF_INT;
            if(dist[a] == INF_INT) dist[b] = INF_INT;
            if(dist[a] != -INF_INT && dist[b] < dist[a] + c){
                dist[b] = min(dist[a] + c, (ll)INF_INT);
            }
        }
    }
    ll od = dist[n];
    
    for(int i=1;i<=n;i++){
        for(auto &[a, b, c] : edg){
            if(a == b && c > 0 && dist[a] != -INF_INT) dist[a] = INF_INT;
            if(dist[a] == INF_INT) dist[b] = INF_INT;
            if(dist[a] != -INF_INT && dist[b] < dist[a] + c){
                dist[b] = min(dist[a] + c, (ll)INF_INT);
            }
        }
    }
    
    if(dist[n] == od && dist[n] < INF_INT){
        if(dist[n] == -INF_INT) cout << "0\n";
        else cout << max(dist[n], 0LL) << "\n";
    }else cout << "-1\n";
    
}
