#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1 << 20;
int cnt[N];
int vis[N];
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
        for(int i=0;i<n;i++) cin >> v[i];
        map<int,int> mp;
        for(int i=0;i<n;i++) mp[v[i]]++;
        vector<pair<int,int>> vp;
        for(int i=0;i<n;i++){
            if(mp[v[i]]){
                vp.push_back({v[i], mp[v[i]]});
                mp[v[i]] = 0;
            }
        }
        ll ans = 0;
        for(int i=0;i<vp.size();i++){
            for(int j=i+1;j<vp.size();j++){
                int xr = vp[i].first ^ vp[j].first;
                // cnt[xr] += vp[i].second * vp[j].second;
                ll aux = vp[i].second * vp[j].second;
                ll a1 = ((vp[i].second) * (vp[i].second - 1));
                ll a2 = ((vp[j].second) * (vp[j].second - 1));
                ans += 2*a1*a2;
                ans += 8 * cnt[xr] * aux;
                cnt[xr] += aux;
                
            }
        }
        //two cases, equal numbers (2-2) and all different numbers
        //equal numbers already computed
        
        for(int i=0;i<vp.size();i++){
            for(int j=i+1;j<vp.size();j++){
                int xr = vp[i].first ^ vp[j].first;
                cnt[xr] = 0;
            }
        }
        cout << ans << "\n";
    }
}
