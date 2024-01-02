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
        int n;
        cin >> n;
        vector<int> a(n+1), b(n+1);
        vector<vector<int>> oc(n+1);
        for(int i=1;i<=n;i++){
            cin >> a[i];
            oc[a[i]].push_back(i);
        }
        for(int i=1;i<=n;i++) cin >> b[i];
        ll ans = 0;
        for(int i=1;i*i<=2*n;i++){
            int prod = i*i;
            map<ll,ll> mp;
            for(auto x : oc[i]) mp[b[x]]++;
            for(auto [k, v] : mp){
                int v2 = prod - k;
                if(v2 < k) continue;
                if(v2 == k){
                    ans += (v * (v-1))/2;
                }else{
                    if(mp.count(v2)) ans += mp[v2] * v;
                }
            }
        }
        for(ll i=1;i*i<=2*n;i++){
            vector<ll> cnt1(n+1, 0), cnt2(n+1, 0);
            for(ll j=1;j<=n;j++){
                ll val = i*a[j] - b[j];
                if(a[j] == i) cnt1[b[j]]++;
                else if(a[j] > i && val > 0 && val <=n) cnt2[val]++;
            }
            for(int j=1;j<=n;j++) ans += cnt1[j]*cnt2[j];
        }
        
        cout << ans << "\n";
    }
}
