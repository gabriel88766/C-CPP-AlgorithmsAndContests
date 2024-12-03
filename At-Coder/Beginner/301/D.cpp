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
    string s;
    ll n;
    cin >> s >> n;
    reverse(s.begin(), s.end());
    int cnt = 0;
    for(auto c : s) if(c == '?') cnt++;
    auto getCmsk = [&](ll msk){
        int p = 0;
        ll ans = 0;
        for(int i=0;i<s.size();i++){
            if(s[i] == '1') ans += 1LL << i;
            else if(s[i] == '?'){
                if(msk & (1LL << p)) ans += 1LL << i;
                p++;
            }
        }
        return ans;
    };
    if(getCmsk(0) <= n){
        ll lo = 0, hi = (1LL << cnt)-1;
        while(lo != hi){
            ll mid = lo + (hi - lo + 1)/2;
            if(getCmsk(mid) <= n) lo = mid;
            else hi = mid - 1;
        }
        cout << getCmsk(lo) << "\n";
    }else cout << "-1\n";
}
