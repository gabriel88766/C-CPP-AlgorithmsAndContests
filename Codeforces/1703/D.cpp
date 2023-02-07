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
    //freopen("in", "r", stdin); test input
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        map<string, int> mp;
        vector<string> v(n);
        for(int i=0;i<n;i++){
            cin >> v[i];
            mp[v[i]]++;
        }
        string ans;
        for(int i=0;i<n;i++){
            bool ok = false;
            for(int j = 1; j < v[i].size(); j++){
                string s1 = v[i].substr(0, j);
                string s2 = v[i].substr(j, v[i].size()-j);
                if(mp[s1] && mp[s2]) ok = true;
            }
            if(ok) ans += "1";
            else ans += "0";
        }
        cout << ans << "\n";
    }
}
