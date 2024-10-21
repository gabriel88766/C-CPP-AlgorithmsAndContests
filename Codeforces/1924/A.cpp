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
        int n, m, k;
        cin >> n >> k >> m;
        string s;
        cin >> s;
        vector<bool> ok(k, false);
        string ans = "";
        for(auto c : s){
            if(c-'a' < k) ok[c-'a'] = true;
            bool allok = true;
            for(int j=0;j<k;j++) if(!ok[j]) allok = false;
            if(allok){
                ans += c;
                for(int j=0;j<k;j++) ok[j] = false;
            }
        }
        if(ans.size() >= n) cout << "YES\n";
        else{
            for(int j=0;j<k;j++){
                if(!ok[j]){
                    ans += (char)('a' + j);
                    break;
                }
            }
            while(ans.size() != n) ans += 'a';
            cout << "NO\n" << ans << "\n";
        }
    }
}
