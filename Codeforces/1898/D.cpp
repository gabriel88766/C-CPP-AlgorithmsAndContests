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
        vector<ll> a(n), b(n);
        for(int i=0;i<n;i++) cin >> a[i];
        for(int i=0;i<n;i++) cin >> b[i];
        vector<pair<ll,ll>> v;
        ll sum = 0;
        for(int i=0;i<n;i++){
            sum += abs(a[i] - b[i]);
            if(a[i] >= b[i]) v.push_back({a[i], b[i]});
            else v.push_back({b[i], a[i]}); 
        }
        ll lg = INF_LL, bl = 0;
        for(int i=0;i<n;i++){
            lg = min(lg, v[i].first);
            bl = max(bl, v[i].second);
        }
        if(bl > lg) sum += 2*(bl - lg);
        cout << sum << "\n";
    }
}
