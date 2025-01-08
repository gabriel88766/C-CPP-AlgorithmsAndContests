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
        vector<int> v(n+1);
        for(int i=1;i<=n;i++) cin >> v[i];
        int idx = -1;
        for(int i=1;i<=n;i++){
            if(abs(v[i]) != 1) idx = i;
        }
        if(idx == -1){
            int l = 0, r = 0, mn = 0, mx = 0, ps = 0;
            for(int i=1;i<=n;i++){
                ps += v[i];
                l = min(l, ps - mx);
                r = max(r, ps - mn);
                mx = max(mx, ps);
                mn = min(mn, ps);
            }
            cout << r - l + 1 << "\n";
            for(int i=l;i<=r;i++) cout << i << " ";
            cout << "\n";
        }else{
            int l = 0, r = 0, mn = 0, mx = 0, ps = 0;
            for(int i=1;i<idx;i++){
                ps += v[i];
                l = min(l, ps - mx);
                r = max(r, ps - mn);
                mx = max(mx, ps);
                mn = min(mn, ps);
            }
            mn = mx = ps = 0;
            for(int i=idx+1;i<=n;i++){
                ps += v[i];
                l = min(l, ps - mx);
                r = max(r, ps - mn);
                mx = max(mx, ps);
                mn = min(mn, ps);
            }
            int mnl = 0, mxl = 0, mnr, mxr;
            ps = 0;
            for(int i=1;i<idx;i++){
                ps += v[i];
                mnl = min(mnl, ps);
                mxl = max(mxl, ps);
            }
            ps += v[idx];
            mnr = mxr = ps;
            for(int i=idx+1;i<=n;i++){
                ps += v[i];
                mnr = min(mnr, ps);
                mxr = max(mxr, ps);
            }
            vector<int> ans;
            for(int i=l;i<=r;i++) ans.push_back(i);
            for(int i=mnr-mxl;i<=mxr-mnl;i++) ans.push_back(i);
            sort(ans.begin(), ans.end());
            ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
            cout << ans.size() << "\n";
            for(auto x : ans) cout << x << " ";
            cout << "\n";
        }
    }
}
