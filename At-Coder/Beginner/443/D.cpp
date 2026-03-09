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
        ll ans = 0;
        int n;
        cin >> n;
        vector<pair<int, int>> vp;
        for(int i=1;i<=n;i++){
            int x;
            cin >> x;
            vp.push_back({x, i});
        }
        vector<int> pl(n+1, -1);
        sort(vp.begin(), vp.end());
        set<int> sx;
        for(auto [x, j] : vp){
            if(sx.size() == 0){
                sx.insert(j);
                pl[j] = x;
            }else{
                auto it = sx.lower_bound(j);
                int mxv = INF_INT;
                if(it != sx.end()){
                    mxv = min(mxv, pl[*it] + (*it - j)); 
                }
                if(it != sx.begin()){
                    mxv = min(mxv, pl[*prev(it)] + (j - *prev(it)));
                }
                mxv = min(mxv, x);
                if(x > mxv) ans += x - mxv;
                pl[j] = mxv;
                sx.insert(j);
            }
        }
        cout << ans << "\n";
    }
}
