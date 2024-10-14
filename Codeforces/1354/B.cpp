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
        int ans = INF_INT;
        vector<vector<int>> v(4);
        for(int i=0;i<s.size();i++){
            v[s[i]-'0'].push_back(i);
        }
        for(int i=0;i<s.size();i++){
            int l = i, r = i;
            for(int j=1;j<=3;j++){
                auto it = lower_bound(v[j].begin(), v[j].end(), i);
                if(it == v[j].end()) r = INF_INT;
                else r = max(r, *it);
            }
            if(r != INF_INT) ans = min(ans, r-l+1);
        }

        if(ans == INF_INT) cout << "0\n";
        else cout << ans << "\n";
    }
}
