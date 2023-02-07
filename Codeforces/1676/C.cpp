#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int t;
    cin >> t;
    while(t--){
        int n, sz;
        cin >> n >> sz;
        vector<string> v;
        for(int i=0;i<n;i++){
            string s;
            cin >> s;
            v.push_back(s);
        }
        int ans = 1e9+1;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int curs = 0;
                for(int k=0;k<sz;k++){
                    curs += abs(v[i][k] - v[j][k]);
                }
                ans = min(ans, curs);
            }
        }
        cout << ans << "\n";

    }
}
