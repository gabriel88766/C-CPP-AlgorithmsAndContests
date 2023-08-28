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
        int n;
        cin >> n;
        vector<vector<char>> v(n, vector<char>(n));
        vector<vector<int>> rl(n, vector<int>(n, 0)), rr(n, vector<int>(n, 0)), rv(n, vector<int>(n, 0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin >> v[i][j];
            }
        }
        ll ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                
                int x = rl[i][j]+rr[i][j]+rv[i][j];
                if(v[i][j] == '1') x++;
                if(x % 2){
                    rv[i][j] += 1;
                    if(i+1 < n){
                        if(j-1 >= 0) rl[i+1][j-1] += 1;
                        if(j+1 < n) rr[i+1][j+1] += 1;
                    }
                    ans++;
                }
                if(i+1 < n){
                    rv[i+1][j] += rv[i][j]+rl[i][j]+rr[i][j];
                    if(j-1 >= 0) {rl[i+1][j-1] += rl[i][j]; }
                    if(j+1 < n) {rr[i+1][j+1] += rr[i][j]; }
                }
            }
        }
        cout << ans << "\n";
    }
}
