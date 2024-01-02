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
        string s, t;
        cin >> s >> t;
        int sz1 = s.size(), sz2 = t.size();
        int ans = sz1 + sz2;
        for(int i=1;i<=min(sz1, sz2);i++){
            //check if some substring s, t, same size is equal. if ok, ans = sz1 + sz2 - 2*i;
            bool ok = false;
            for(int j=0;j<=s.size()-i;j++){
                for(int k=0;k<=t.size()-i;k++){
                    if(s.substr(j, i) == t.substr(k, i)){
                        ok = true;
                    }
                }
            }
            if(ok) ans = sz1 + sz2 - 2*i;
        }
        cout << ans << "\n";
    }
}
