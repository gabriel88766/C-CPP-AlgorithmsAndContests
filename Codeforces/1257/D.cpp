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
        int n;
        cin >> n;
        vector<int> v(n), ttk(n+1);
        for(int i=0;i<n;i++) cin >> v[i];
        int m;
        cin >> m;
        vector<pair<int,int>> vp(m);
        for(int i=0;i<m;i++){
            cin >> vp[i].second >> vp[i].first;
        }
        sort(vp.begin(), vp.end(), greater<pair<int,int>>());
        int curm = 0, p = 0;
        for(int i=n;i>=1;i--){
            while(p < m && vp[p].first == i){
                curm = max(curm, vp[p].second);
                p++;
            }
            ttk[i] = curm;
        }
        bool ok = true;
        int ksp = 0, mc = 0, ans = 0;
        for(int i=0;i<n;i++){
            if(ttk[ksp+1] >= max(mc, v[i])){
                ksp++;
                mc = max(mc, v[i]);
            }else{
                if(ksp == 0){ //case can't even kill the first
                    ans = -1;
                    break;
                }
                ans++;
                if(ttk[1] >= v[i]){
                    ksp = 1;
                    mc = v[i];
                }else{
                    ans = -1;
                    break;
                }
            }
        }
        if(ans != -1) ans++;
        cout << ans << "\n";
        
    }
}
