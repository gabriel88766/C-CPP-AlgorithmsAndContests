#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e6+1;
int dp[N][2][2];
pair<int, int> par[N][2][2];
int ans[N], v[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i=1;i<=n;i++){
            for(int j=0;j<2;j++){
                for(int k=0;k<2;k++){
                    dp[i][j][k] = INF_INT;
                    par[i][j][k] = {-1, -1};
                }
            }
        }
        
        v[0] = INF_INT;
        for(int i=0;i<2;i++){
            dp[0][i][1] = -INF_INT;
        }
        for(int i=1;i<=n;i++){
            cin >> v[i];
            for(int j=0;j<2;j++){
                for(int k=0;k<2;k++){
                    for(int lj=0;lj<2;lj++){
                        for(int lk=0;lk<2;lk++){
                            int x1, x2;
                            if(lj == 0){
                                if(lk == 0) x1 = v[i-1];
                                else x1 = -v[i-1];
                                x2 = dp[i-1][lj][lk];
                            }else{
                                if(lk == 0) x2 = v[i-1];
                                else x2 = -v[i-1];
                                x1 = dp[i-1][lj][lk];
                            }
                            if(j == 0){
                                if(k == 0){
                                    if(v[i] > x1 && dp[i][j][k] > x2){
                                        dp[i][j][k] = x2;
                                        par[i][j][k] = {lj, lk};
                                    }
                                }else{
                                    if(-v[i] > x1 && dp[i][j][k] > x2){
                                        dp[i][j][k] = x2;
                                        par[i][j][k] = {lj, lk};
                                    }
                                }
                            }else{
                                if(k == 0){
                                    if(v[i] > x2 && dp[i][j][k] > x1){
                                        dp[i][j][k] = x1;
                                        par[i][j][k] = {lj, lk};
                                    }
                                }else{
                                    if(-v[i] > x2 && dp[i][j][k] > x1){
                                        dp[i][j][k] = x1;
                                        par[i][j][k] = {lj, lk};
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        bool ok = false;
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                if(dp[n][j][k] != INF_INT){
                    ok = true;
                    int cj = j, ck = k, cn = n;
                    while(cn >= 1){
                        if(ck == 0) ans[cn] = v[cn];
                        else ans[cn] = -v[cn];
                        auto &[nj, nk] = par[cn][cj][ck];
                        cj = nj;
                        ck = nk;
                        cn--;
                    }
                    cout << "YES\n";
                    for(int i=1;i<=n;i++) cout << ans[i] << " ";
                    cout << "\n";
                    break;
                }
            }
            if(ok) break;
        }
        if(!ok) cout << "NO\n";

    }
}
