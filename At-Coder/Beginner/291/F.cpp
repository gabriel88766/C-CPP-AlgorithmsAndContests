#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e5+3;
int dist[N], ans[N], dist2[N];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    vector<string> v(n+1);
    for(int i=1;i<=n;i++) cin >> v[i];
    memset(dist, 63, sizeof(dist));
    memset(dist2, 63, sizeof(dist2));
    for(int i=2;i<=n;i++) ans[i] = INF_INT;
    dist[n] = 0; dist2[1] = 0;
    for(int i=(n-1);i>=1;i--){
        for(int j=0;j<m;j++){
            if(v[i][j] == '1') dist[i] = min(dist[i], dist[i+j+1] + 1);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<m;j++){
            if(v[i][j] == '1') dist2[i+j+1] = min(dist2[i+j+1], dist2[i] + 1);
        }
    }

    for(int i=2;i<n;i++){
        
        for(int j=(i-m+1); j < i; j++){
            if(j <= 0) continue;
            for(int k=0;k<m;k++){
                if(j+k+1 <= i) continue;
                if(j+k+1 > n) continue;
                if(v[j][k] == '1' && dist2[j] != INF_INT && dist[j+k+1] != INF_INT){
                    ans[i] = min(ans[i], dist2[j] + 1 + dist[j+k+1]);
                }
            }
        }

        if(ans[i] != INF_INT) cout << ans[i] << " ";
        else cout << "-1 ";
    }
}   
