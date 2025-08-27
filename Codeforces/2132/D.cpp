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
    auto get_qnt = [&](ll n){
        ll ans = 0;
        ll aux = 1, cnt = 1;
        while(aux <= n){
            if(10*aux <= n){
                ans += 9 * aux * cnt;
            }else{
                ans += (n - aux + 1) * cnt;
            }
            cnt++;
            aux *= 10;
        }
        return ans;
    };
    auto get_sd = [&](ll n){
        //sum of digits all numbers from 1 to n
        string s = to_string(n);
        ll ans = 0;
        ll aux = 1;
        for(int j=s.size()-1; j >= 0;j--){
            ll x = (j == s.size() - 1 ? 0 : stoll(s.substr(j+1, s.size() - j-1)));
            n /= 10;
            ans += n * aux * 45; 
            for(int d = 1; d< s[j] - '0';d++){
                ans += aux * d;
            }
            ans += (s[j] - '0') * ( x + 1);
            aux *= 10;
        }
        return ans;
    };
    int t;
    cin >> t;
    while(t--){
        ll k;
        cin >> k;
        //get quantity of numbers up to n
        ll lo = 0, hi = 1e16;
        while(lo != hi){
            ll mid = lo + (hi - lo + 1)/2;
            if(get_qnt(mid) < k) lo = mid;
            else hi = mid - 1;
        }
        ll ans = get_sd(lo);
        string nn = to_string(lo + 1);
        k -= get_qnt(lo);
        for(int j=0;j<k;j++){
            ans += nn[j] - '0';
        }
        cout << ans << "\n";
        
    }
}
