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
        int n, d;
        cin >> n >> d;
        vector<int> v(n+1);
        for(int i=1;i<=n;i++) cin >> v[i];
        int mn = INF_INT, idx = -1;
        for(int i=1;i<=n;i++){
            if(v[i] - v[i-1] - 1 < mn){
                mn = v[i] - v[i-1] - 1;
                idx = i;
            }
        }
        vector<int> chk;
        if(idx == 1) chk = {1};
        else chk = {idx-1, idx};
        int ans = mn;
        for(auto x : chk){
            int cmn = INF_INT;
            for(int i=1;i<=n;i++){
                if(x == i) continue;
                if(x == i-1) cmn = min(cmn, v[i] - v[i-2] - 1);
                else cmn = min(cmn, v[i] - v[i-1] - 1);
            }
            int cmx = 0;
            for(int i=1;i<=n;i++){
                if(x == i) continue;
                if(x == i-1){
                    cmx = max(cmx, (v[i] - v[i-2]-2)/2);
                }else{
                    cmx = max(cmx, (v[i] - v[i-1]-2)/2);
                }
            }
            if(x == n){
                cmx = max(cmx, d - v[n-1] - 1);
            }else{
                cmx = max(cmx, d - v[n] - 1);
            }
            cmn = min(cmn, cmx);
            ans = max(ans, cmn);
        }
        cout << ans << "\n";
    }
} 