#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll func(ll s, ll k){
    ll t[12];
    bool vis[10];
    for(int i=0;i<=9;i++) vis[i] = false;
    t[0] = s;
    vis[t[0] % 10] = true;
    int ind;
    for(ind = 1; ;ind++){
        t[ind] = t[ind-1] + (t[ind-1] % 10);
        if(vis[t[ind] % 10]) break;
        vis[t[ind] % 10] = true;
    }
    
    int ind2 = 0;
    for(;; ind2++){
        if(t[ind2] % 10 == t[ind] % 10) break;
    }
    if(k <= ind) return t[k];
    else{
        ll dif = ind - ind2;
        k -=  ind2;
        ll r = k % dif;
        ll q = k / dif;
        ll ans = q*(t[ind] - t[ind2]); 
        return ans + t[ind2+r];
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        ll s, k;
        cin >> s >> k;
         ll ans = 0;
        if(k <= 100){
            for(ll i = 0; i <= k; i++){
                ll res = func(s, i) * (k - i);
                if(res > ans){
                    ans = res;
                }
            }
        }else{
            ll dx = func(s, 105) - func(s, 5); 
            for(int i=0;i<=5;i++){
                ll res = func(s, i) * (k - i);
                if(res > ans){
                    ans = res;
                }
            }
            if(dx != 0){
                ll goal = (5*k - s)/10;
                for(ll i = max(goal-10, 0LL);i<=min(goal+10, k);i++){
                    ll res = func(s, i) * (k - i);
                    if(res > ans){
                        ans = res;
                    }
                }
                
            }
        }
        cout << ans << "\n";
    }
}
