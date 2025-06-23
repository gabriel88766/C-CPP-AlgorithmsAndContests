#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;
 
ll n, k;
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
   
    cin >> n >> k;
    // k = 1e9;
    map<ll, ll> mpt, mpx;
    string s = to_string(n);
    mpt[1] = mpx[1] = 1;
    ll ans = 0;
    for(int i=s.size()-1;i>=0;i--){
        map<ll, ll> nmpt, nmpx;
        for(int d=0;d<s[i]-'0'; d++){
            for(auto [a, v] : mpx){
                nmpt[a*d] += v;
                if(i == 0 && d != 0 && a*d <= k){
                    ans += v;
                }
            }
        }
        for(auto [a, v] : mpt){
            nmpt[a*(s[i]-'0')] += v;
            if(i == 0 && s[i] != '0' && a*(s[i]-'0') <= k) ans += v;
        }
        for(int d=0;d<=9;d++){
            for(auto [a, v] : mpx){
                nmpx[a * d] += v;
                if(i != 0 && d != 0 && a*d <= k) ans += v;
            }
        }
        mpx = nmpx;
        mpt = nmpt;
    }
    
    cout << ans << "\n";
}
