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
        int n, q;
        cin >> n >> q;
        vector<pair<ll,ll>> vp;
        vector<pair<ll,ll>> am;
        ll len = 0;
        bool ok = false;
        ll y = 0;
        for(int i=0;i<n;i++){
            ll b, x;
            cin >> b >> x;
            if(ok) continue;
            if(b == 1){
                vp.push_back({len, x});
                len++;
                y++;
            }else{
                x++;
                if(INF_LL/x > len){
                    len *= x;
                    am.push_back({y, x});
                    y = 0;
                }else{
                    ok = true;
                }
            }
        }
        if(y != 0) am.push_back({y, 1});
        for(int i=0;i<q;i++){
            ll x;
            cin >> x;
            x--;
            x %= len;
            int p = am.size() - 1;
            ll clen = len;
            while(true){
                clen /= am[p].second;
                x = x % clen;
                auto it = lower_bound(vp.begin(), vp.end(), make_pair(x ,0LL));
                if(it != vp.end() && it->first == x){
                    cout << it->second << " ";
                    break;
                }else{
                    clen -=  am[p].first;
                    p--;
                    assert(clen != 0);
                    x %= clen;
                }
            }
        }
        cout << "\n";
    }
}
