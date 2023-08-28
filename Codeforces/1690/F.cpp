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
        vector<ll> mmans;
        int n;
        string s;
        cin >> n >> s;
        s = " " + s;
        vector<int> v(n+1);
        for(int i=1;i<=n;i++) cin >> v[i];

        //get all cycles
        vector<bool> used(n+1, false);
        vector<vector<int>> allc;
        for(int i=1;i<=n;i++){
            if(used[i]) continue;
            vector<int> cycle;
            auto cur = i;
            do{
                cycle.push_back(cur);
                cur = v[cur];
            }while(i != cur);
            for(auto x : cycle){
                used[x] = true;
            }
            allc.push_back(cycle);
        }
        vector<bool> cycok(allc.size(), false);
        //all possible cycle len
        string t = s;
        for(int i = 1; i <= n; i++){
            auto aux = t;
            for(int j=1;j<=n;j++){
                t[v[j]] = aux[j];
            }
            for(int j = 0;j <allc.size(); j++){
                if(cycok[j]) continue;
                bool ok = true;
                for(int k=0;k<allc[j].size();k++){
                    if(s[allc[j][k]] != t[allc[j][k]]){
                        ok = false;
                        break;
                    }
                }
                if(ok){
                    cycok[j] = true;
                    mmans.push_back(i);
                }
            }
        }
        ll ans = 1;
        for(int i=0;i<mmans.size();i++){
            ans = (ans/__gcd(ans, mmans[i]))*mmans[i];
        }
        cout << ans << "\n";
    }
}
