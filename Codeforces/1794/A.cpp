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
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<string> pss[21];
        for(int i=0;i<(2*n-2);i++){
            string s;
            cin >> s;
            pss[s.size()].emplace_back(s);
        }
        /*if(n == 2){
            if(s[1][0] == s[1][1]) cout << "YES\n";
            else cout << "NO\n";
            continue;
        }*/
        string cur;
        for(int i=0;i<4;i++){
            cur = pss[1][i%2] + pss[n-1][i/2];
            bool ok = true;
            for(int j=1;j<n;j++){
                bool ok2 = false;
                if(cur.substr(0, j) == pss[j][0] && cur.substr(n-j,j) == pss[j][1]) ok2 = true;
                if(cur.substr(0, j) == pss[j][1] && cur.substr(n-j,j) == pss[j][0]) ok2 = true;
                if(!ok2) ok = false;
            }
            if(ok) break;
        }
        bool ok2 = true;
        for(int i=0;i<n/2;i++){
            if(cur[i] != cur[n-i-1]) ok2 = false;
        }
        if(ok2) cout << "YES\n";
        else cout << "NO\n";
    }
}
