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
    int n, m;
    cin >> n >> m;
    vector<string> vs(n);
    for(int i=0;i<n;i++) cin >> vs[i];
    int ans = 15;
    string oks;
    for(int j=0;j<m;j++) oks += 'o';
    for(int i=0;i<(1 << n);i++){
        int cur = __builtin_popcount(i);
        string curs;
        for(int j=0;j<m;j++) curs += 'x';
        for(int k=0;k<n;k++){
            if(i & (1 << k)){
                for(int j=0;j<m;j++){
                    if(vs[k][j] == 'o') curs[j] = 'o';
                }
            }
        }
        if(curs == oks) ans = min(ans, cur);
    }
    cout << ans << "\n";
}