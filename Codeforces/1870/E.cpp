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
        vector<vector<short>> mex(n+1, vector<short>(n+1));
        //int maxn = 1 << (32 - __builtin_clz(n));
        //vector<vector<bool>> dp(n, vector<bool>(maxn, false));
        vector<short> v(n+1);
        for(int i=1;i<=n;i++) cin >> v[i];
        for(int i=1;i<=n;i++){
            vector<bool> used(n+1, false);
            short m = 0;
            for(int j=i;j<=n;j++){
                used[v[j]] = true;
                while(used[m]) m++;
                mex[i][j] = m;
            }
        }
        vector<set<int>> vs(n+1);
        vs[0].insert(0);
        for(int i=1;i<=n;i++){
            for(auto x : vs[i-1]) vs[i].insert(x);
            for(int j=1;j<=i;j++){
                for(auto x : vs[j-1]){
                    vs[i].insert(x^mex[j][i]);
                }
            }
        }
        cout << *prev(vs[n].end()) << "\n";

    }
}