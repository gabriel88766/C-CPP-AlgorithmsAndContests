#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> v(m), ans(n);
    map<int,int> mp;
    int bp = 0;
    for(int i=0;i<m;i++) cin >> v[i];
    for(int i=0;i<m;i++){
        if(!mp[v[i]]){
            mp[v[i]] = 1;
            ans[bp++] = i+1;
            if(bp == n) break;
        }
    }
    for(int i=bp;i<n;i++) ans[i] = -1;
    reverse(ans.begin(), ans.end());
    for(int i=0;i<n;i++) cout << ans[i] << " ";
    cout << "\n";
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        solve();
    }

}
 