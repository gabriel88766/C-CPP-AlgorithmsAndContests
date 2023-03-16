#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        int tt = n*m;
        vector<vector<ll>> ans(n, vector<ll>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ll val = 0;
                ll aux = 1;
                for(int k=0;k<8;k++){
                    int nowv = 0;
                    if(i & (1 << k)) nowv += 2;
                    if(j & (1 << k)) nowv += 1;
                    val += nowv * aux;
                    aux *= 4;
                }
                ans[i][j] = val;
            }
        }
        cout << tt << "\n";
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout << ans[i][j] << " \n"[j==(m-1)];
            }
        }
    }
}
