#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//bitset<1000000001> bs;
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
            //bs[v[i]] = true;
        }
        ll ans = 0;
        int cnt = 0;
        for(auto p : mp){
            ans += (p.second*(p.second-1)*(p.second-2));
            if(p.first > 1000000){
                for(int j=2;j*p.first<=1000000000;j++){
                    if(p.first % j == 0){
                        if(mp.count(p.first/j) && mp.count(p.first*j)) ans += p.second*mp[p.first/j]*mp[p.first*j];
                    }
                }
            }else{
                for(int j=1;j*j<=p.first;j++){
                    if(p.first % j == 0){
                        if(j!=1 && mp.count(p.first/j) && mp.count(p.first*j)) ans+=p.second*mp[p.first/j]*mp[p.first*j];
                        if(mp.count(j) && mp.count(p.first*(p.first/j)) && j*j != p.first) ans+=p.second*mp[j]*mp[p.first*(p.first/j)];
                    }
                }
            }
        }
        cout << ans << "\n";
    }
}
