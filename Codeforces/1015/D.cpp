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
    ll n, k, s;
    cin >> n >> k >> s;
    ll minv = k;
    ll maxv = k*(n-1);
    if(s <= maxv && s >= minv){
        vector<int> ans = {1};
        ll lo = 0, hi = k;
        while(lo != hi){
            ll mid = lo + (hi - lo + 1) / 2;
            ll stp = k-mid + mid*(n-1);
            if(stp > s) hi = mid - 1;
            else lo = mid;
        }
        for(int i=1;i<=lo;i++){
            if(ans.back() == 1) ans.push_back(n);
            else ans.push_back(1);
        }
        
        if(lo != k){
            s -= (n-1) * lo;
            ll dif = s - (k-lo);
            if(ans.back() == 1) ans.push_back(dif+2);
            else ans.push_back(n-dif-1);
            for(int i=lo+2;i<=k;i++){
                if(ans.back() != 1) ans.push_back(ans.back()-1);
                else ans.push_back(2);
            }
        }   
        cout << "YES\n";
        for(int i=1;i<=k;i++) cout << ans[i] << " ";
        cout << "\n";

    }else cout <<  "NO\n";
}
