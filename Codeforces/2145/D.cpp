#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

pair<int, int> par[31][31][901];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        if(k == 0){
            for(int i=1;i<=n;i++) cout << i << " ";
            cout << "\n";
        }else{
            int mx = n * (n-1);
            mx /= 2;
            pair<int, int> null = {0, 0};
            for(int i=1;i<=n;i++){
                for(int j=1;j<=i;j++){
                    for(int u=0;u<=mx;u++){
                        par[i][j][u] = null;
                    }
                }
            }
            
            par[1][1][0] = {-1, -1};
            for(int i=2;i<=n;i++){
                for(int j=1;j<i;j++){
                    for(int u=0;u<=mx;u++){
                        if(par[i-1][j][u] != null){
                            int xx = (n - i + 1) * (i - j);
                            par[i][i][u + xx] = {j, u};
                            par[i][j][u] = {j, u};
                        }
                    }
                }
            }
            bool ok = false;
            for(int j=1;j<=n;j++){
                if(par[n][j][k] != null){
                    vector<bool> gr(n+1, false);
                    int cj = j, ck = k;
                    int cnt = 0;
                    for(int u=n;u>=2;u--){
                        if(par[u][cj][ck].first != cj){
                            gr[u] = true;
                            cnt++;
                            auto pr = par[u][cj][ck];
                            cj = pr.first, ck = pr.second;
                        }
                    }
                    int c1 = cnt + 1, c2 = cnt;
                    for(int i=1;i<=n;i++){
                        if(gr[i]){
                            cout << c2-- << " ";
                        }else{
                            cout << c1++ << " ";
                        }
                    }
                    cout << "\n";
                    ok = true;
                    break;
                    
                }
            }
            if(!ok) cout << "0\n";
        }
    }
}
