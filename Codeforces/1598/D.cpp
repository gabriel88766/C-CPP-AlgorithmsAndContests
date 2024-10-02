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
        ll n;
        cin >> n;
        ll tt = 0;
        for(ll i=n-1;i>=2;i--){
            ll nws = i;
            nws *= (i-1);
            nws /= 2;
            tt += nws;
        }
        map<ll, ll> mp1, mp2;
        vector<pair<int,int>> vp(n);
        for(int i=0;i<n;i++){
            int a, b;
            cin >> a >> b;
            mp1[a]++;
            mp2[b]++;
            vp[i] = {a, b};
        }
        for(int i=0;i<n;i++){
            auto [a, b] = vp[i];
            ll f1 = mp1[a] - 1;
            ll f2 = mp2[b] - 1;
            tt -= f1 * f2;
        }
        cout << tt << "\n";
    }
}
