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
        string s;
        cin >> n;
        cin >> s;
        vector<ll> v(n), ps(n+1, 0);
        vector<pair<int,int>> range;
        ll ans = 0;
        for(int i=0;i<n;i++){
            cin >> v[i];
            ps[i+1] = ps[i] + v[i];
        }
        int l0 = -1;
        for(int j=0;j<n;j++){
            if(s[j] == '0'){
                if(l0 != -1){
                    if(l0 != (j-1)) range.emplace_back(l0, j-1);
                }
                l0 = j;
            }
        }
        if(l0 != (n-1) && l0 != -1) range.emplace_back(l0, n-1);
        for(int i=0;i<n;i++){
            if(s[i] != '1') break;
            else ans += v[i];
        }

        for(auto x : range){
            ll minv = INF_INT;
            for(int i = x.first; i<= x.second; i++){
                minv = min(minv, v[i]);
            }
            ans += (ps[x.second+1]-ps[x.first]-minv);
        }
        cout << ans << "\n";
    }
}
 