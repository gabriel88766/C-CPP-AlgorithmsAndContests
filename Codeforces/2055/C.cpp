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
        string s;
        cin >> s;
        vector<vector<ll>> gr(n, vector<ll>(m));
        vector<vector<ll>> ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin >> gr[i][j];
            }
        } 
        ans = gr;
        int ci = 0, cj = 0;
        for(auto &c : s){
            if(c == 'D'){
                ll sum = 0;
                for(int j=0;j<m;j++) sum += ans[ci][j];
                ans[ci][cj] = -sum;
                ci++;
            }else{
                ll sum = 0;
                for(int i=0;i<n;i++) sum += ans[i][cj];
                ans[ci][cj] = -sum;
                cj++;
            }
        }
        ll sum = 0;
        for(int j=0;j<m;j++) sum += ans[n-1][j];
        ans[n-1][m-1] = -sum;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
    }
}
