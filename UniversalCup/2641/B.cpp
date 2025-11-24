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
        ll n, m, a, b;
        cin >> n >> m >> a >> b;
        ll q0 = 0;
        map<int, int> mp;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int x;
                cin >> x;
                if(x == 0) q0++;
                else mp[x]++;
            }
        }
        vector<ll> freq;
        for(auto [k, v] : mp) freq.push_back(v);
        sort(freq.begin(), freq.end(), greater<ll>());
        ll ans = (n*m - q0) * a; //1 transparent layer + colors
        ll s1 = 0, s2 = 0;
        ll n0 = n * m - q0;
        for(int i=1;i<=freq.size();i++){
            ll cur = q0 * i * b; //make colors 0
            //all except current and already painted must be a
            s1 += freq[i-1];
            cur += (n0 - s1) * a;
            //sum the transparent layers of others and the current
            s2 += freq[i-1] * (i-1) * b; //sum current to others
            cur += s2;
            ans = min(ans, cur);
        }
        cout << ans << "\n";
    }
}   
