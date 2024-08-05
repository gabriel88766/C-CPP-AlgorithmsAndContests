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
        ll n, k, h, w;
        cin >> n >> k  >> w >> h;
        string s;
        cin >> s;
        map<ll, map<ll, ll>> mp; 
        ll cgh = 0, cgw = 0;
        for(int i=1;i<=n;i++){
            auto c = s[i-1];
            if(c == 'L'){
                cgw--;
            }else if(c == 'R'){
                cgw++;
            }else if(c == 'U'){
                cgh++;
            }else{
                cgh--;
            }
            if(cgw >= 2*w) cgw -= 2*w;
            if(cgw < 0) cgw += 2*w;
            if(cgh >= 2*h) cgh -= 2*h;
            if(cgh < 0) cgh += 2*h;
            mp[cgw][cgh]++;
        }
        ll curh = 0, curw = 0, ans = 0;
        for(int i=1;i<=k;i++){
            ll difh = (2*h - curh) % (2*h);
            ll difw = (2*w - curw) % (2*w);
            if(mp.count(difw) && mp[difw].count(difh)) ans += mp[difw][difh];
            curh = (curh + cgh) % (2*h);
            curw = (curw + cgw) % (2*w);
        }
        cout << ans << "\n";
    }
}
