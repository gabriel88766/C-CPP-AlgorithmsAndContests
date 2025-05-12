#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll neg = -1e12;
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        ll n, k;
        cin >> n >> k;
        string s;
        vector<ll> ans(n+1);
        cin >> s;
        s = " " + s;
        for(int i=1;i<=n;i++) cin >> ans[i];
        ll ms = 0;
        ll cs = 0;
        int c0 = 0, c1 = n+1;
        for(int i=1;i<=n;i++){
            if(s[i] == '0'){
                cs = 0;
                if(c0 == 0) c0 = i;
                else if(c1 == n+1) c1 = i;
            }else{
                cs += ans[i];
            }
            if(cs < 0) cs = 0;
            ms = max(cs, ms);
        }
        if(ms > k) cout << "No\n";
        else if(ms == k){
            cout << "Yes\n";
            for(int i=1;i<=n;i++) if(s[i] == '0') ans[i] = neg;
            for(int i=1;i<=n;i++) cout << ans[i] << " ";
            cout << "\n";
        }else{
            if(c0 > 0){
                cout << "Yes\n";
                for(int i=c1;i<=n;i++){
                    if(s[i] == '0') ans[i] = neg;
                }
                ms = 0;
                ll ps = 0;
                for(int i=1;i<c1;i++){
                    ps += ans[i];
                    if(ps < 0 && i < c0) ps = 0;
                    if(i >= c0) ms = max(ps, ms);
                }
                ans[c0] = k - ms;
                for(int i=1;i<=n;i++) cout << ans[i] << " ";
                cout << "\n";
            }else cout << "No\n";
        }
    }
}
