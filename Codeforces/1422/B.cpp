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
        vector<vector<int>> v(n, vector<int> (m));
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin >> v[i][j];
        ll ans = 0;
        for(int i=0;i<n/2;i++){
            for(int j=0;j<m/2; j++){
                vector<int> aux = {v[i][j], v[n-i-1][j], v[i][m-j-1], v[n-i-1][m-j-1]};
                sort(aux.begin(), aux.end());
                for(int k=0;k<4;k++) ans += abs(aux[k]-aux[1]);
            }
        }
        if(n%2){
            for(int i=0;i<m/2;i++) ans += abs(v[n/2][i] - v[n/2][m-i-1]);
        }
        if(m%2){
            for(int i=0;i<n/2;i++) ans += abs(v[i][m/2] - v[n-i-1][m/2]);
        }
        cout << ans << "\n";
    }
}
