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
        vector<ll> a(n), b(n);
        set<ll> s1, s2;
        for(int i=0;i<n;i++){
            cin >> a[i];
            s1.insert(a[i]);
        }
        for(int i=0;i<n;i++){
            cin >> b[i];
            s2.insert(b[i]);
        }
        ll ans = INF_LL;
        for(int i=0;i<16;i++){
            //1 means 1->1
            //2 means 1->n
            //4 means n->1
            //8 means n->n;
            ll cur = 0;
            vector<bool> ok(4);
            for(int j=0;j<4;j++){
                if(i & (1 << j)){
                    if(j == 0 || j == 1) ok[0] = true;
                    if(j == 2 || j == 3) ok[1] = true;
                    if(j == 0 || j == 2) ok[2] = true;
                    if(j == 1 || j == 3) ok[3] = true;
                    if(j == 0) cur += abs(a[0] - b[0]);
                    if(j == 1) cur += abs(a[0] - b.back());
                    if(j == 2) cur += abs(a.back() - b[0]);
                    if(j == 3) cur += abs(a.back() - b.back());
                }
            }
            for(int j=0;j<4;j++){
                if(!ok[j]){
                    ll opt1, opt2;
                    auto &s = (j < 2 ? s2 : s1);
                    ll val;
                    if(j == 0) val = a[0];
                    if(j == 1) val = a.back();
                    if(j == 2) val = b[0];
                    if(j == 3) val = b.back(); 
                    auto it = s.lower_bound(val);
                    if(it != s.end()) opt1 = *it - val;
                    else opt1 = INF_LL;
                    if(it != s.begin()) opt2 = val - *prev(it);
                    else opt2 = INF_LL;
                    cur += min(opt1, opt2);
                }
            }
            ans = min(ans, cur);
        }

        cout << ans << "\n";
    }
}
