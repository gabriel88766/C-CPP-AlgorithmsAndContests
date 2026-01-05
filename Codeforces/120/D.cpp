#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int gr[51][51];
int ps[51];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> gr[i][j];
        }
    }
    int u[3];
    cin >> u[0] >> u[1] >> u[2];
    sort(u, u+3);
    int ans = 0;
    for(int i=1;i<=n;i++){
        ps[i] = 0;
        for(int j=1;j<=m;j++) ps[i] += gr[i][j];
        ps[i] += ps[i-1];
    }
    for(int i=1;i<n;i++){
        for(int j=i+1;j<n;j++){
            int v[3];
             v[0] = ps[i];
             v[1] = ps[j] - ps[i];
             v[2] = ps[n] - ps[j];
            sort(v, v+3);
            if(v[0] == u[0] && v[1] == u[1] && v[2] == u[2]){
                ans++;
            }
        }
    }
    for(int j=1;j<=m;j++){
        ps[j] = 0;
        for(int i=1;i<=n;i++) ps[j] += gr[i][j];
        ps[j] += ps[j-1];
    }
    for(int i=1;i<m;i++){
        for(int j=i+1;j<m;j++){
            int v[3];
             v[0] = ps[i];
             v[1] = ps[j] - ps[i];
             v[2] = ps[m] - ps[j];
            sort(v, v+3);
            if(v[0] == u[0] && v[1] == u[1] && v[2] == u[2]){
                ans++;
            }
        }
    }
    cout << ans << "\n";
}   
