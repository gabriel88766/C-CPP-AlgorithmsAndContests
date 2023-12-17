#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
int dp[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
     //ans = 32-__builtin_clz(imax);
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        vector<vector<int>> v(26);
        for(int i=0;i<s.size();i++){
            for(int j=0;j<26;j++){
                if((s[i]-'a') == j) continue;
                v[j].push_back(i);
            }
        }
        int ans = INF_INT;
        for(int i=0;i<26;i++){
            int mv = 0;
            int cur = -1, cnt = 0;
            for(auto x : v[i]){
                if(x == cur + 1) cnt++,cur++;
                else{
                    mv = max(mv, cnt);
                    cnt = 1, cur = x;
                }
            }
            mv = max(mv, cnt);
            if(mv) ans = min(ans, 32-__builtin_clz(mv));
            else ans = 0;
        }
        cout << ans << "\n";
    }
}
