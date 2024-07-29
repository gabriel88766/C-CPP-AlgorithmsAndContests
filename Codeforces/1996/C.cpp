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
        int n, q;
        string s, t;
        cin >> n >> q;
        cin >> s >> t;
        s = " " + s;
        t = " " + t;
        vector<vector<int>> c1(n+1, vector<int>(26)), c2(n+1, vector<int>(26));
        for(int i=1;i<=n;i++){
            for(int k=0;k<26;k++){
                c1[i][k] = c1[i-1][k];
                c2[i][k] = c2[i-1][k];
            }
            c1[i][s[i]-'a']++;
            c2[i][t[i]-'a']++;
        }
        for(int i=0;i<q;i++){
            int l, r;
            cin >> l >> r;
            int ans = 0;
            for(int k=0;k<26;k++){
                int d1 = c1[r][k] - c1[l-1][k];
                int d2 = c2[r][k] - c2[l-1][k];
                if(d1 < d2) ans += d2-d1;
            }
            cout << ans << "\n";
        }
    }
}
