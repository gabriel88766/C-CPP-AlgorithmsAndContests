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
        string s = "vika";
        int n, m;
        cin >> n >> m;
        vector<string> v(n);
        for(int i=0;i<n;i++){
            cin >> v[i];
        }
        int p = 0;
        for(int i=0;i<m;i++){
            bool ok = false;
            for(int j=0;j<n;j++){
                if(p < 4 && v[j][i] == s[p]) ok = true;
            }
            if(ok) p++;
        }
        if(p == 4) cout << "YES\n";
        else cout << "NO\n";
    }
}
