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
        int n, m;
        cin >> n >> m;
        vector<int> vn, vm;
        int sz = n + m + 1;
        vector<ll> a(sz), b(sz);
        for(int i=0;i<sz;i++) cin >> a[i];
        for(int i=0;i<sz;i++){
            cin >> b[i];
            if(b[i] > a[i]) vm.push_back(i);
            else vn.push_back(i);
        }
        if(vm.size() > m){
            vm.swap(vn);
            a.swap(b);
            swap(n, m);
        }
        ll aux = 0;
        for(auto x : vm) aux += b[x];
        ll ts = 0;
        for(int i=0;i<n;i++) ts += a[vn[i]];
        for(int i=n;i<vn.size();i++) ts += b[vn[i]];
        
        for(int i=0;i<sz;i++){
            ll ans;
            if(a[i] > b[i]){
                //type 1
                ans = ts + aux;
                if(n && i <= vn[n-1]){
                    ans -= a[i];
                    ans += a[vn[n]] - b[vn[n]];
                }else ans -= b[i];
            }else{
                //type 2
                ans = ts + aux;
                ans -= b[i];
            }
            cout << ans << " ";
        }
        cout << "\n";
    }
}
