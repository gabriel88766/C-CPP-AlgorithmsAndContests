#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

tuple<int, int, int> ps2[100], ps3[1000];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<string> v(n+1);
        string s;
        for(int i=1;i<=n;i++) cin >> v[i];
        cin >> s;
        memset(ps2, 0, sizeof(ps2));
        memset(ps3, 0, sizeof(ps3));
        for(int i=1;i<=n;i++){
            for(int j=2;j<m;j++){
                int num = stoi(v[i].substr(j-2, 3));
                ps3[num] = {j-1, j+1, i};
            }
            for(int j=1;j<m;j++){
                int num = stoi(v[i].substr(j-1, 2));
                ps2[num] = {j, j+1, i};
            }
        }
        vector<pair<int, int>> dp(m+1, make_pair(-1, -1));
        dp[0] = {0, 0};
        for(int i=2;i<=m;i++){
            if(i >= 2){
                int n2 = stoi(s.substr(i-2, 2));
                if(ps2[n2] != make_tuple(0, 0, 0) && dp[i-2] != make_pair(-1, -1)){
                    dp[i] = {2, n2};
                }
            }
            if(i >= 3){
                int n3 = stoi(s.substr(i-3, 3));
                if(ps3[n3] != make_tuple(0, 0, 0) && dp[i-3] != make_pair(-1, -1)){
                    dp[i] = {3, n3};
                }   
            }
        }
        if(dp[m] != make_pair(-1, -1)){
            vector<tuple<int, int, int>> ans;
            int cur = m;
            while(cur != 0){
                if(dp[cur].first == 2){
                    ans.push_back(ps2[dp[cur].second]);
                    cur -= 2;
                }else{
                    ans.push_back(ps3[dp[cur].second]);
                    cur -= 3;
                }
            }
            reverse(ans.begin(), ans.end());
            cout << ans.size() << "\n";
            for(auto &[a, b, c] : ans){
                cout << a << " " << b << " " << c << "\n";
            }
        }else cout << "-1\n";
    }
}
