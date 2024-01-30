#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int M = 20;
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
        vector<int> loc(n+1);
        for(int i=1;i<=n;i++) cin >> loc[i];
        vector<vector<int>> forth(n+1, vector<int>(M));
        vector<vector<int>> back(n+1, vector<int>(M));
        for(int i=1;i<=n;i++){
            if(i != 1){
                if(i == n || abs(loc[i-1] - loc[i]) < abs(loc[i+1] - loc[i])) back[i][0] = 1;
                else back[i][0] = abs(loc[i-1] - loc[i]);
            }
            if(i != n){
                if(i == 1 || abs(loc[i+1] - loc[i]) < abs(loc[i-1] - loc[i])) forth[i][0] = 1;
                else forth[i][0] = abs(loc[i+1] - loc[i]);
            }
        }
        for(int j=1;j<M;j++){
            for(int i=1;i<=n;i++){
                if(i - (1 << (j-1)) >= 1) back[i][j] = back[i][j-1] + back[i - (1 << (j-1))][j-1];
                else back[i][j] = back[i][j-1];
                if(i + (1 << (j-1)) <= n) forth[i][j] = forth[i][j-1] + forth[i + (1 << (j-1))][j-1];
                else forth[i][j] = forth[i][j-1];
            }
        }
        int m;
        cin >> m;
        for(int i=0;i<m;i++){
            int a, b;
            cin >> a >> b;
            int dif = abs(a-b);
            int ans = 0;
            if(a > b){
                //back  
                for(int j=0;j<M;j++){
                    if(dif & (1 << j)){
                        ans += back[a][j];
                        a -= (1 << j);
                    }
                }
            }else{
                for(int j=0;j<M;j++){
                    if(dif & (1 << j)){
                        ans += forth[a][j];
                        a += (1 << j);
                    }
                }
            }
            cout << ans << "\n";
        }
    }
}
