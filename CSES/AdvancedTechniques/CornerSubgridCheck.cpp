#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

bitset<3005> bs[3005];
char gr[3005][3005];
int cn[3005];
int p = 0;
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, k;
    cin >> n >> k; //n up to 3000 and k up to 26
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> gr[i][j];
        }
    }
    
    for(int i=0;i<k;i++){
        for(int j=1;j<=n;j++) bs[j].reset();
        p = 0;
        bool ok = false;
        for(int j=1;j<=n;j++){
            p = 0;
            for(int u=1;u<=n;u++){
                if(gr[j][u] - 'A' == i){
                    cn[p++] = u;
                }
            }
            for(int u=0;u<p;u++){
                for(int v=u+1;v<p;v++){
                    if(bs[cn[u]][cn[v]]){
                        ok = true;
                        break;
                    }else bs[cn[u]][cn[v]] = true;
                }
                if(ok) break;
            }
            if(ok) break;
        }
        
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
}
