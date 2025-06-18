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
        vector<vector<int>> v(n, vector<int>(m));
        int mx = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin >> v[i][j];
                mx = max(mx, v[i][j]);
            }
        }
        vector<int> c1(n), c2(m);
        int cc = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(v[i][j] == mx){
                    c1[i]++;
                    c2[j]++;
                    cc++;
                }
            }
        }
        bool ok = false;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int ct = c1[i] + c2[j];
                if(v[i][j] == mx) ct--;
                if(ct == cc) ok = true;
            }
        }
        if(ok) cout << mx-1 << "\n";
        else cout << mx << "\n";
    }
}
