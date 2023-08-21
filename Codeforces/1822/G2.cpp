#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

bitset<1000000001> bs;
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
        vector<int> v(n);
        map<ll,ll> mp;
        for(int i=0;i<n;i++){
            cin >> v[i];
            mp[v[i]]++; //nlogn
            bs[v[i]] = true;
        }
        ll ans = 0;
        int cnt = 0;
        for(auto p : mp){
            ans += (p.second*(p.second-1)*(p.second-2));
            for(int j=2; p.first*j*j <= 1000000000; j++){
                if(bs[p.first*j] && bs[p.first*j*j]) ans += p.second*mp[j*p.first]*mp[j*j*p.first];
            }
        }
        cout << ans << "\n";
    }
}
