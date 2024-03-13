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
    string t;
    cin >> t;
    int sz = t.size();
    vector<int> dp(t.size() + 1, -1);
    dp[0] = 0;
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int m;
        cin >> m;
        vector<string> v;
        for(int j=0;j<m;j++){
            string s;
            cin >> s;
            v.push_back(s);
        }
        for(int j=sz-1;j>=0;j--){
            if(dp[j] != -1){
                for(int k=0;k<v.size();k++){
                    if(v[k].size() + j <= sz && v[k] == t.substr(j, v[k].size())){
                        if(dp[j+v[k].size()] == -1) dp[j+v[k].size()] = dp[j] + 1;
                        else dp[j+v[k].size()] = min(dp[j+v[k].size()], dp[j] + 1);
                    }
                }
            }
        }
    }
    cout << dp[sz] << "\n";
}
