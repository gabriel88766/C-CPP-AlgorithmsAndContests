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
        string s;
        cin >> s;
        int n = s.size();
        vector<bool> ok(n, false);
        int cok = 0;
        for(int i=0;i<n;i++){
            if(i+3 < n && s.substr(i, 4) == "1100"){
                cok++;
                ok[i] = true;
            }
        }
        int q;
        cin >> q;
        while(q--){
            int j;
            char v;
            cin >> j >> v;
            --j;
            s[j] = v;
            for(int i=max(0, j-3);i<=j;i++){
                if(ok[i]){
                    cok--;
                    ok[i] = false;
                }
                if(i+3 < n && s.substr(i, 4) == "1100"){
                    cok++;
                    ok[i] = true;
                }
            } 
            if(cok) cout << "YES\n";
            else cout << "NO\n";
            
        }
    }
}
