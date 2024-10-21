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
        int m;
        cin >> m;
        vector<vector<int>> v(2, vector<int>(m+1));
        for(int i=0;i<2;i++){
            for(int j=1;j<=m;j++){
                cin >> v[i][j];
            }
        }
        auto v1 = v, v2 = v;
        for(int j=1;j<=m;j++){
            v1[0][j] -= (j - 1);
            v2[1][j] -= (j - 1);
        }
        for(int j=m;j>=1;j--){
            v1[1][j] -= (m + (m - j));
            v2[0][j] -= (m + (m - j));
        }
        v1[0][1] = -INF_INT;
        v2[0][1] = -INF_INT;
        vector<int> m1(m+1, -1), m2(m+1, -1);
        for(int j=m;j>=1;j--){
            if(j != m){
                m1[j] = m1[j+1];
                m2[j] = m2[j+1];
            }
            m1[j] = max({m1[j], v1[0][j], v1[1][j]});
            m2[j] = max({m2[j], v2[0][j], v2[1][j]});
        }
        int ans = m1[1] + 2*m;
        int ct = -1;
        v[0][1] = -1;
        for(int i=1;i<m;i++){
            if(i % 2){
                //up then down
                if(ct >= v[0][i]){
                    ct++;
                }else ct = v[0][i] + 1;
                if(ct >= v[1][i]){
                    ct++;
                }else ct = v[1][i] + 1;
                int lt = ct  - i;
                int cur = max(0, m2[i+1] - lt) + 2*(m-i) + ct;
                ans = min(ans, cur);
            }else{
                if(ct >= v[1][i]){
                    ct++;
                }else ct = v[1][i] + 1;
                if(ct >= v[0][i]){
                    ct++;
                }else ct = v[0][i] + 1;
                int lt = ct - i;
                int cur = max(0, m1[i+1] - lt) + 2*(m-i) + ct;
                ans = min(ans, cur);
            }
        }
        cout << ans << "\n";

    }
}   
